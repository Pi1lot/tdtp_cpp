#include "headers/StepGenerator.hpp"
#include <random>
#include <chrono>

StepGenerator::StepGenerator(int seed)
    : rng((seed == 0) ? std::mt19937(std::random_device{}()) : std::mt19937(seed))
{
    setSeed(seed);
}

std::vector<double> StepGenerator::generateTimeSeries(int length)
{
    std::vector<double> out;
    if (length <= 0) return out;
    out.reserve(length);

    int prev = 0;
    out.push_back(static_cast<double>(prev));

    for (int i = 1; i < length; ++i) {
        if (coin(rng)) {
            out.push_back(static_cast<double>(prev));
        } else {
            prev = dist(rng);
            out.push_back(static_cast<double>(prev));
        }
    }

    return out;
}
