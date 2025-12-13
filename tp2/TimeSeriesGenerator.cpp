#include "headers/TimeSeriesGenerator.hpp"
#include <iostream>
#include <iomanip>

TimeSeriesGenerator::TimeSeriesGenerator()
 : seed(0)
{
}

TimeSeriesGenerator::TimeSeriesGenerator(int s)
 : seed(s)
{
}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& ts)
{
	std::cout << std::fixed << std::setprecision(6);
	for (size_t i = 0; i < ts.size(); ++i) {
		std::cout << ts[i];
		if (i + 1 < ts.size())
			std::cout << ", ";
	}
	std::cout << std::endl;
}
