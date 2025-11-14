#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include "searching_algorithm.h"

using namespace std;

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const vector<int>& elements, int cible) override;
};

#endif