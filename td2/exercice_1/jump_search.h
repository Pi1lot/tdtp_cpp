#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H
#include <cmath>

#include "searching_algorithm.h"
using namespace std;


class JumpSearch : public SearchingAlgorithm {
public:
    int search(const vector<int>& elements, int cible) override;
};
#endif