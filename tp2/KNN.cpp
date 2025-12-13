#include "headers/KNN.hpp"
#include "headers/Similarity.hpp"
#include <algorithm>
#include <map>
#include <stdexcept>

KNN::KNN(int k, const std::string& measure)
    : k(k), similarity_measure(measure)
{
}

void KNN::setTrainingData(const TimeSeriesDataset& dataset)
{
    trainData = dataset.getData();
    trainLabels = dataset.getLabels();
}

double KNN::calculateDistance(const std::vector<double>& a, const std::vector<double>& b) const
{
    if (similarity_measure == "euclidean" || similarity_measure == "euclidean_distance") {
        return euclidean_distance(a, b);
    } else if (similarity_measure == "dtw" || similarity_measure == "dtw_distance") {
        return dtw_distance(a, b);
    } else {
        return euclidean_distance(a, b);
    }
}

int KNN::majorityVote(const std::vector<int>& neighborLabels) const
{
    std::map<int, int> labelCounts;
    
    for (int label : neighborLabels) {
        labelCounts[label]++;
    }

    int maxCount = 0;
    int majorityLabel = neighborLabels[0];
    
    for (const auto& pair : labelCounts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            majorityLabel = pair.first;
        }
    }

    return majorityLabel;
}

int KNN::predict(const std::vector<double>& series) const
{
    if (trainData.empty()) {
        throw std::runtime_error("No training data set");
    }

    std::vector<std::pair<double, int>> distances;
    distances.reserve(trainData.size());

    for (size_t i = 0; i < trainData.size(); ++i) {
        double dist = calculateDistance(series, trainData[i]);
        distances.push_back({dist, trainLabels[i]});
    }

    std::sort(distances.begin(), distances.end(),
        [](const std::pair<double, int>& a, const std::pair<double, int>& b) {
            return a.first < b.first;
        });

    std::vector<int> neighborLabels;
    int effectiveK = std::min(k, static_cast<int>(distances.size()));
    
    for (int i = 0; i < effectiveK; ++i) {
        neighborLabels.push_back(distances[i].second);
    }

    return majorityVote(neighborLabels);
}

std::vector<int> KNN::predict(const TimeSeriesDataset& testDataset) const
{
    const auto& testData = testDataset.getData();
    std::vector<int> predictions;
    predictions.reserve(testData.size());

    for (const auto& series : testData) {
        predictions.push_back(predict(series));
    }

    return predictions;
}

double KNN::evaluate(const TimeSeriesDataset& testDataset) const
{
    const auto& testLabels = testDataset.getLabels();
    std::vector<int> predictions = predict(testDataset);

    if (predictions.empty()) {
        return 0.0;
    }

    int correct = 0;
    for (size_t i = 0; i < predictions.size(); ++i) {
        if (predictions[i] == testLabels[i]) {
            correct++;
        }
    }

    return static_cast<double>(correct) / static_cast<double>(predictions.size());
}

double KNN::evaluate(const TimeSeriesDataset& trainDataset, const TimeSeriesDataset& testDataset, const std::vector<int>& ground_truth)
{
    trainData = trainDataset.getData();
    trainLabels = trainDataset.getLabels();

    std::vector<int> predictions = predict(testDataset);

    if (predictions.empty()) {
        return 0.0;
    }

    int correct = 0;
    for (size_t i = 0; i < predictions.size(); ++i) {
        if (predictions[i] == ground_truth[i]) {
            correct++;
        }
    }

    return static_cast<double>(correct) / static_cast<double>(predictions.size());
}
