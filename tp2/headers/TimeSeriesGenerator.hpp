#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
using namespace std;

class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int);
    virtual ~TimeSeriesGenerator() = default;

    virtual vector<double> generateTimeSeries(int length) = 0;
    static void printTimeSeries(const vector<double>& ts);
    
    int getSeed() const { return seed; }
    void setSeed(int s) { seed = s; }
};

#endif