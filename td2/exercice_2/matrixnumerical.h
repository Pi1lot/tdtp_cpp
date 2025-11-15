#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "matrixbase.h"
#include <type_traits>

template<typename T>
typename enable_if<is_arithmetic<T>::value, vector<vector<T>>>::type
getCoFactor(const vector<vector<T>>& matrix, size_t p, size_t q, size_t n);

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
    static_assert(is_arithmetic<T>::value, "Il faut un type arithmétique pour créer une instance");
public:
    MatrixNumerical();
    MatrixNumerical(size_t r, size_t c);

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other) const;

    T getDeterminant(const vector<vector<T>>& mat, size_t n) const;
    MatrixNumerical<T> getInverse() const;
    static MatrixNumerical<T> getIdentity(size_t n);
};

#include "matrixnumerical.tpp"
#endif
