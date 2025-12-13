#include "headers/GaussianGenerator.hpp"
#include <cmath>
#include <limits>
#include <chrono>
#include <iostream>

GaussianGenerator::GaussianGenerator(int m, int sd, int seed)
    : mean(m), standardDeviation(sd), rng( (seed==0) ? std::mt19937(std::random_device{}()) : std::mt19937(seed) )
{
    setSeed(seed);
}

double GaussianGenerator::boxMullerSample()
{
    if (hasSpare) {
        hasSpare = false;
        return spare * static_cast<double>(standardDeviation) + static_cast<double>(mean);
    }

    double u1 = 0.0;
    double u2 = 0.0;
    do {
        u1 = uni(rng);
    } while (u1 <= std::numeric_limits<double>::min());
    u2 = uni(rng);

    const double two_pi = 2.0 * std::acos(-1.0);
    double mag = std::sqrt(-2.0 * std::log(u1));
    double z0 = mag * std::cos(two_pi * u2);
    double z1 = mag * std::sin(two_pi * u2);

    spare = z1;
    hasSpare = true;

    return z0 * static_cast<double>(standardDeviation) + static_cast<double>(mean);
}

std::vector<double> GaussianGenerator::generateTimeSeries(int length)
{
    std::vector<double> out;
    out.reserve(length);
    for (int i = 0; i < length; ++i) {
        out.push_back(boxMullerSample());
    }
    return out;
}
