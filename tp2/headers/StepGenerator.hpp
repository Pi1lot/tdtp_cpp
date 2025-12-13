#ifndef STEPGENERATOR_HPP
#define STEPGENERATOR_HPP

#include "TimeSeriesGenerator.hpp"
#include <random>
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator(int seed = 0);
    virtual std::vector<double> generateTimeSeries(int length) override;

private:
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist{0, 100};
    std::bernoulli_distribution coin{0.5};
};

#endif
