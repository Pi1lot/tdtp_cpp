#include "headers/Similarity.hpp"
#include <cmath>
#include <limits>
#include <algorithm>

double euclidean_distance(const std::vector<double>& x, const std::vector<double>& y)
{
    if (x.size() != y.size()) {
        size_t minLen = std::min(x.size(), y.size());
        double sum = 0.0;
        for (size_t i = 0; i < minLen; ++i) {
            double diff = x[i] - y[i];
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }

    double sum = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        double diff = x[i] - y[i];
        sum += diff * diff;
    }
    return std::sqrt(sum);
}

double dtw_distance(const std::vector<double>& x, const std::vector<double>& y)
{
    size_t L1 = x.size();
    size_t L2 = y.size();

    if (L1 == 0 || L2 == 0) {
        return 0.0;
    }

    std::vector<std::vector<double>> D(L1 + 1, std::vector<double>(L2 + 1, std::numeric_limits<double>::infinity()));
    
    D[0][0] = 0.0;

    for (size_t i = 1; i <= L1; ++i) {
        for (size_t j = 1; j <= L2; ++j) {
            double d = (x[i - 1] - y[j - 1]) * (x[i - 1] - y[j - 1]);
            double minVal = std::min({D[i][j - 1], D[i - 1][j], D[i - 1][j - 1]});
            D[i][j] = d + minVal;
        }
    }

    return std::sqrt(D[L1][L2]);
}
