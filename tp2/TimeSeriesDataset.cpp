#include "headers/TimeSeriesDataset.hpp"
#include <cmath>
#include <numeric>
#include <stdexcept>

TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool train)
    : znormalize(znorm), isTrain(train), maxLength(0), numberOfSamples(0)
{
}

std::vector<double> TimeSeriesDataset::zNormalize(const std::vector<double>& series)
{
    if (series.empty()) {
        return series;
    }

    double sum = std::accumulate(series.begin(), series.end(), 0.0);
    double mean = sum / static_cast<double>(series.size());

    double sq_sum = 0.0;
    for (const auto& val : series) {
        sq_sum += (val - mean) * (val - mean);
    }
    double stddev = std::sqrt(sq_sum / static_cast<double>(series.size()));

    if (stddev < 1e-10) {
        stddev = 1.0;
    }

    std::vector<double> normalized;
    normalized.reserve(series.size());
    for (const auto& val : series) {
        normalized.push_back((val - mean) / stddev);
    }

    return normalized;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label)
{
    std::vector<double> toAdd;
    
    if (znormalize) {
        toAdd = zNormalize(series);
    } else {
        toAdd = series;
    }

    data.push_back(toAdd);
    labels.push_back(label);

    if (static_cast<int>(toAdd.size()) > maxLength) {
        maxLength = static_cast<int>(toAdd.size());
    }

    numberOfSamples++;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series)
{
    std::vector<double> toAdd;
    
    if (znormalize) {
        toAdd = zNormalize(series);
    } else {
        toAdd = series;
    }

    data.push_back(toAdd);
    labels.push_back(-1);

    if (static_cast<int>(toAdd.size()) > maxLength) {
        maxLength = static_cast<int>(toAdd.size());
    }

    numberOfSamples++;
}
