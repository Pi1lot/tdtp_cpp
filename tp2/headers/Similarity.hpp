#ifndef SIMILARITY_HPP
#define SIMILARITY_HPP

#include <vector>

double euclidean_distance(const std::vector<double>& x, const std::vector<double>& y);
double dtw_distance(const std::vector<double>& x, const std::vector<double>& y);

#endif
