#ifndef COMPLEX2D_H
#define COMPLEX2D_H

#include <iostream>

class Complex2D {
private:
    double re; 
    double im; 
public:

    Complex2D();
    Complex2D(double r, double i);
    Complex2D(double val);
    Complex2D(const Complex2D& other);

    void setRe(double r);
    void setIm(double i);
    double getRe() const;
    double getIm() const;

    Complex2D operator+(const Complex2D& other) const;
    Complex2D operator-(const Complex2D& other) const;
    Complex2D operator*(const Complex2D& other) const;
    Complex2D operator/(const Complex2D& other) const;

    bool operator>(const Complex2D& other) const;
    bool operator<(const Complex2D& other) const;

   Complex2D conjugue() const;
    void print() const;
};

#endif
