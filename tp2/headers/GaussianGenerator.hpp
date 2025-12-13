#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.hpp"
#include <vector>
#include <random>

class GaussianGenerator : public TimeSeriesGenerator {
public:
    GaussianGenerator(int mean = 0, int standardDeviation = 1, int seed = 0);
    virtual std::vector<double> generateTimeSeries(int length) override;

    int getMean() const { return mean; }
    int getStandardDeviation() const { return standardDeviation; }
    void setMean(int m) { mean = m; }
    void setStandardDeviation(int sd) { standardDeviation = sd; }

private:
    int mean;
    int standardDeviation;
    std::mt19937 rng;
    std::uniform_real_distribution<double> uni{0.0, 1.0};
    bool hasSpare{false};
    double spare{0.0};
    double boxMullerSample();
};

#endif
