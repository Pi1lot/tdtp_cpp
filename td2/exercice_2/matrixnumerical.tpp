#ifndef MATRIXNUMERICAL_TPP
#define MATRIXNUMERICAL_TPP

template<typename T>
typename enable_if<is_arithmetic<T>::value, vector<vector<T>>>::type
getCoFactor(const vector<vector<T>>& matrix, size_t p, size_t q, size_t n) {
    vector<vector<T>> temp;
    temp.reserve(n - 1);
    for(size_t i = 0; i < n; i++) {
        if(i == p) continue;
        vector<T> row;
        for(size_t j = 0; j < n; j++) {
            if(j == q) continue;
            row.push_back(matrix[i][j]);
        }
        temp.push_back(row);
    }
    return temp;
}

template<typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>() {}

template<typename T>
MatrixNumerical<T>::MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}

// ===== Opérateurs =====
template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) const {
    if(this->rows != other.rows || this->cols != other.cols)
        throw invalid_argument("Les dimensions ne permettent pas d'opérations+");
    MatrixNumerical<T> result(this->rows, this->cols);
    for(size_t i=0;i<this->rows;i++)
        for(size_t j=0;j<this->cols;j++)
            result.data[i][j] = this->data[i][j] + other.data[i][j];
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& other) const {
    if(this->rows != other.rows || this->cols != other.cols)
        throw invalid_argument("Les dimensions ne permettent pas d'opérations+");
    MatrixNumerical<T> result(this->rows, this->cols);
    for(size_t i=0;i<this->rows;i++)
        for(size_t j=0;j<this->cols;j++)
            result.data[i][j] = this->data[i][j] - other.data[i][j];
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& other) const {
    if(this->cols != other.rows)
        throw invalid_argument("Les dimensions ne permettent pas d'opérations+");
    MatrixNumerical<T> result(this->rows, other.cols);
    for(size_t i=0;i<this->rows;i++)
        for(size_t j=0;j<other.cols;j++)
            for(size_t k=0;k<this->cols;k++)
                result.data[i][j] += this->data[i][k] * other.data[k][j];
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& other) const {
    return (*this) * other.getInverse();
}

// ===== Déterminant =====
template<typename T>
T MatrixNumerical<T>::getDeterminant(const vector<vector<T>>& mat, size_t n) const {
    T det = 0;
    if(n == 1) return mat[0][0];
    int sign = 1;
    for(size_t f=0; f<n; f++){
        auto temp = getCoFactor(mat, 0, f, n);
        det += sign * mat[0][f] * getDeterminant(temp, n-1);
        sign = -sign;
    }
    return det;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    if(this->rows != this->cols)
        throw invalid_argument("Il fautu ne matrice carrée en entrée");

    T det = getDeterminant(this->data, this->rows);
    if(det == 0)
        throw runtime_error("SImpossible de trouver l'inverse");

    size_t n = this->rows;
    MatrixNumerical<T> adj(n, n);

    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            auto temp = getCoFactor(this->data, i, j, n);
            int sign = ((i+j)%2==0)?1:-1;
            adj.data[j][i] = sign * getDeterminant(temp, n-1);
        }
    }

    MatrixNumerical<T> inv(n, n);
    for(size_t i=0;i<n;i++)
        for(size_t j=0;j<n;j++)
            inv.data[i][j] = adj.data[i][j] / det;

    return inv;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(size_t n){
    MatrixNumerical<T> I(n,n);
    for(size_t i=0;i<n;i++)
        I.data[i][i] = T(1);
    return I;
}

#endif
