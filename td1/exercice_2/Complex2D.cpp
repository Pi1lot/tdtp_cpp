#include "Complex2D.h"
#include <cmath> 

Complex2D::Complex2D() : re(0.0), im(0.0) {}
Complex2D::Complex2D(double r, double i) : re(r), im(i) {}
Complex2D::Complex2D(double val) : re(val), im(val) {}
Complex2D::Complex2D(const Complex2D& other) : re(other.re), im(other.im) {}

void Complex2D::setRe(double r) { re = r; }
void Complex2D::setIm(double i) { im = i; }
double Complex2D::getRe() const { return re; }
double Complex2D::getIm() const { return im; }

Complex2D Complex2D::operator+(const Complex2D& other) const {
    return Complex2D(re + other.re, im + other.im);
}
Complex2D Complex2D::operator-(const Complex2D& other) const {
    return Complex2D(re - other.re, im - other.im);
}
Complex2D Complex2D::operator*(const Complex2D& other) const {
    return Complex2D(re * other.re - im * other.im, re * other.im + im * other.re);
}
Complex2D Complex2D::operator/(const Complex2D& other) const {
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0) {
        std::cerr << "Can't divide by zero" << std::endl;
        return Complex2D();
    }
    return Complex2D(
        (re * other.re + im * other.im) / denom,
        (im * other.re - re * other.im) / denom
    );
}

bool Complex2D::operator>(const Complex2D& other) const {
    double norm1 = re * re + im * im;
    double norm2 = other.re * other.re + other.im * other.im;
    return norm1 > norm2;
}

bool Complex2D::operator<(const Complex2D& other) const {
    double norm1 = re * re + im * im;
    double norm2 = other.re * other.re + other.im * other.im;
    return norm1 < norm2;
}

Complex2D Complex2D::conjugue() const {
    return Complex2D(re, -im);
}

void Complex2D::print() const {
    std::cout << "(" << re << ", " << im << "i)" << std::endl;
}
