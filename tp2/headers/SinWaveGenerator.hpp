#ifndef SINWAVEGENERATOR_HPP
#define SINWAVEGENERATOR_HPP

#include "TimeSeriesGenerator.hpp"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
public:
    SinWaveGenerator(double amplitude = 1.0, double frequency = 1.0, double phase = 0.0, int seed = 0);
    virtual std::vector<double> generateTimeSeries(int length) override;

    double getAmplitude() const { return amplitude; }
    double getFrequency() const { return frequency; }
    double getPhase() const { return phase; }

    void setAmplitude(double a) { amplitude = a; }
    void setFrequency(double w) { frequency = w; }
    void setPhase(double p) { phase = p; }

private:
    double amplitude;
    double frequency;
    double phase;
};

#endif
