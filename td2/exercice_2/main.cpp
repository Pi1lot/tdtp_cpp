#include "matrixbase.h"
#include "matrixnumerical.h"

using namespace std;
int main() {
    cout << "Création d'une matrice\n";
    MatrixBase<int> base(2, 3);
    base.display();
    cout << "Rows: " << base.getRows() << ", Cols: " << base.getCols() << "\n";

    vector<vector<int>> elems = {{1, 2, 3}, {4, 5, 6}};
    base.addElements(elems);
    cout << "Ajouts d'éléments à la matrice :\n";
    base.display();


    cout << "\n Test d'une instantiation de matrix numerical\n";
    MatrixNumerical<double> A(3, 3);
    vector<vector<double>> elemsA = {
        {2, -1, 0},
        {-1, 2, -1},
        {0, -1, 2}
    };
    A.addElements(elemsA);
    cout << "Matrix A après ajout de valeurs\n";
    A.display();

    cout << "Rows: " << A.getRows() << ", Cols: " << A.getCols() << "\n";



    double detA = A.getDeterminant(A.getElements(), A.getRows());
    cout << "Détermiant matrice A: " << detA << "\n";

    MatrixNumerical<double> invA = A.getInverse();
    cout << "Inverse de A:\n";
    invA.display();


    auto cofactor = getCoFactor(A.getElements(), 0, 0, A.getRows());
    cout << "Cofacteur de A:\n";
    for (auto &row : cofactor) {
        for (auto &val : row) cout << setw(6) << val << " ";
        cout << "\n";
    }

    auto I = MatrixNumerical<double>::getIdentity(3);
    cout << "Identité de la matrice 3x3:\n";
    I.display();

    cout << "A+I:\n";
    (A + I).display();

    cout << "A-I:\n";
    (A - I).display();

    cout << "A*I:\n";
    (A * I).display();

    cout << "A/I:\n";
    (A / I).display();

    MatrixNumerical<double> C(3, 2);
    vector<vector<double>> elemsC = {{1, 2}, {3, 4}, {5, 6}};
    C.addElements(elemsC);
    cout << "Matrice C 3x2:\n";
    C.display();

    cout << "A * C (MAtrices non carrées):\n";
    (A * C).display();


    return 0;
}
