#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "searching_algorithm.h"
using namespace std;


class BinarySearch : public SearchingAlgorithm {

public:
    int search(const vector<int>& elements, int cible) override;
};

#endif