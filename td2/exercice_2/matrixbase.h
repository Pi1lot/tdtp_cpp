#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;
template<typename T>
class MatrixBase {
protected:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();
    MatrixBase(size_t r, size_t c);
    size_t getRows() const;
    size_t getCols() const;
    vector<vector<T>>& getElements();

    void addElements(const vector<vector<T>>& elements);

    void display() const;
};

#include "matrixbase.tpp"
#endif
