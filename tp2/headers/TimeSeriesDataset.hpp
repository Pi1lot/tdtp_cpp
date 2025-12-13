#ifndef TIMESERIESDATASET_HPP
#define TIMESERIESDATASET_HPP

#include <vector>
#include <string>

class TimeSeriesDataset {
public:
    TimeSeriesDataset(bool znormalize = false, bool isTrain = true);
    void addTimeSeries(const std::vector<double>& series, int label);
    void addTimeSeries(const std::vector<double>& series);
    static std::vector<double> zNormalize(const std::vector<double>& series);

    bool getZnormalize() const { return znormalize; }
    bool getIsTrain() const { return isTrain; }
    const std::vector<std::vector<double>>& getData() const { return data; }
    const std::vector<int>& getLabels() const { return labels; }
    int getMaxLength() const { return maxLength; }
    int getNumberOfSamples() const { return numberOfSamples; }

    void setZnormalize(bool z) { znormalize = z; }
    void setIsTrain(bool t) { isTrain = t; }

private:
    bool znormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
    int numberOfSamples;
};

#endif
