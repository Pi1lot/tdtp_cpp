#ifndef MATRIXBASE_TPP
#define MATRIXBASE_TPP

template<typename T>
MatrixBase<T>::MatrixBase() : rows(0), cols(0) {}

template<typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c) : rows(r), cols(c) {
    data.resize(rows, vector<T>(cols, T()));
}

template<typename T>
size_t MatrixBase<T>::getRows() const { return rows; }

template<typename T>
size_t MatrixBase<T>::getCols() const { return cols; }

template<typename T>
vector<vector<T>>& MatrixBase<T>::getElements() { return data; }

template<typename T>
void MatrixBase<T>::addElements(const vector<vector<T>>& elements) {
    if(elements.size() != rows || elements[0].size() != cols)
        throw invalid_argument("Les dimensions sont fausses");
    data = elements;
}

template<typename T>
void MatrixBase<T>::display() const {
    cout << "Matrice (" << rows << "x" << cols << "):\n";
    for(const auto& row : data) {
        for(const auto& val : row)
            cout << setw(8) << val << " ";
        cout << "\n";
    }
}

#endif
