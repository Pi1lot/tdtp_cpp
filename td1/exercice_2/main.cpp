#include "Complex2D.h"

int main() {
    Complex2D a(3, 4);
    Complex2D b(1, 2);
    Complex2D c = a + b;
    Complex2D d = a * b;
    Complex2D e = a / b;
    Complex2D f = a - b;

    std::cout << "a = "; a.print();
    std::cout << "b = "; b.print();
    std::cout << "a + b = "; c.print();
    std::cout << "a * b = "; d.print();
    std::cout << "a / b = "; e.print();
    std::cout << "a - b = "; f.print();

    if (a > b)
        std::cout << "a bigger than b or equal" << std::endl;
    else
        std::cout << "a smaller or equal than b" << std::endl;

    return 0;
}
