#include "headers/SinWaveGenerator.hpp"
#include <cmath>

SinWaveGenerator::SinWaveGenerator(double a, double w, double p, int seed)
    : amplitude(a), frequency(w), phase(p)
{
    setSeed(seed);
}

std::vector<double> SinWaveGenerator::generateTimeSeries(int length)
{
    std::vector<double> out;
    if (length <= 0) return out;
    out.reserve(length);

    for (int x = 0; x < length; ++x) {
        double value = amplitude * std::sin(frequency * static_cast<double>(x) + phase);
        out.push_back(value);
    }

    return out;
}
