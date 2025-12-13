#ifndef KNN_HPP
#define KNN_HPP

#include <vector>
#include <string>
#include "TimeSeriesDataset.hpp"

class KNN {
public:
    KNN(int k = 1, const std::string& similarity_measure = "euclidean");
    void setTrainingData(const TimeSeriesDataset& dataset);
    int predict(const std::vector<double>& series) const;
    std::vector<int> predict(const TimeSeriesDataset& testDataset) const;
    double evaluate(const TimeSeriesDataset& testDataset) const;
    double evaluate(const TimeSeriesDataset& trainDataset, const TimeSeriesDataset& testDataset, const std::vector<int>& ground_truth);

    int getK() const { return k; }
    std::string getSimilarityMeasure() const { return similarity_measure; }

    void setK(int newK) { k = newK; }
    void setSimilarityMeasure(const std::string& measure) { similarity_measure = measure; }

private:
    int k;
    std::string similarity_measure;
    std::vector<std::vector<double>> trainData;
    std::vector<int> trainLabels;
    double calculateDistance(const std::vector<double>& a, const std::vector<double>& b) const;
    int majorityVote(const std::vector<int>& neighborLabels) const;
};

#endif
