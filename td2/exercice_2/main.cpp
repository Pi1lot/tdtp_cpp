#include "matrixbase.h"
#include "matrixnumerical.h"

int main() {
    std::cout << "Création d'une matrice\n";
    MatrixBase<int> base(2, 3);
    base.display();
    std::cout << "Rows: " << base.getRows() << ", Cols: " << base.getCols() << "\n";

    std::vector<std::vector<int>> elems = {{1, 2, 3}, {4, 5, 6}};
    base.addElements(elems);
    std::cout << "Ajouts d'éléments à la matrice :\n";
    base.display();


    std::cout << "\n Test d'une instantiation de matrix numerical\n";
    MatrixNumerical<double> A(3, 3);
    std::vector<std::vector<double>> elemsA = {
        {2, -1, 0},
        {-1, 2, -1},
        {0, -1, 2}
    };
    A.addElements(elemsA);
    std::cout << "Matrix A après ajout de valeurs\n";
    A.display();

    std::cout << "Rows: " << A.getRows() << ", Cols: " << A.getCols() << "\n";



    double detA = A.getDeterminant(A.getElements(), A.getRows());
    std::cout << "Détermiant matrice A: " << detA << "\n";

    MatrixNumerical<double> invA = A.getInverse();
    std::cout << "Inverse de A:\n";
    invA.display();


    auto cofactor = getCoFactor(A.getElements(), 0, 0, A.getRows());
    std::cout << "Cofacteur de A:\n";
    for (auto &row : cofactor) {
        for (auto &val : row) std::cout << std::setw(6) << val << " ";
        std::cout << "\n";
    }

    auto I = MatrixNumerical<double>::getIdentity(3);
    std::cout << "Identité de la matrice 3x3:\n";
    I.display();

    std::cout << "A+I:\n";
    (A + I).display();

    std::cout << "A-I:\n";
    (A - I).display();

    std::cout << "A*I:\n";
    (A * I).display();

    std::cout << "A/I:\n";
    (A / I).display();

    MatrixNumerical<double> C(3, 2);
    std::vector<std::vector<double>> elemsC = {{1, 2}, {3, 4}, {5, 6}};
    C.addElements(elemsC);
    std::cout << "Matrice C 3x2:\n";
    C.display();

    std::cout << "A * C (MAtrices non carrées):\n";
    (A * C).display();


    return 0;
}
