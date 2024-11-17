#pragma once
#include <cmath>
#include <iostream>

struct Complex
{
    float re;
    float im;

    Complex() : re(0), im(0) {}
    Complex(float re, float im) : re(re), im(im) {}

    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator*(const Complex& other) const {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    Complex& operator+=(const Complex& other) {
        re += other.re;
        im += other.im;
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        float newRe = re * other.re - im * other.im;
        float newIm = re * other.im + im * other.re;
        re = newRe;
        im = newIm;
        return *this;
    }

    float norm() const {
        return std::sqrt(re * re + im * im);
    }
};

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << "(" << c.re << ", " << c.im << ")";
    return out;
}