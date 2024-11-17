#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

class Number
{
private:
    static const int base = 100;
    char* data;
    std::size_t size;
    std::size_t capacity;

public:
    Number() : data(nullptr), size(1), capacity(1) {
        data = new char[capacity];
        data[0] = 0;
    }

    Number(int a)
    {
        int temp = a;
        capacity = 0;
        while (temp != 0)
        {
            temp /= base;
            capacity += 1;
        }

        if (capacity == 0)
            capacity = 1;

        data = new char[capacity];

        for (int i = 0; i < capacity; ++i)
        {
            data[i] = a % base;
            a /= base;
        }

        size = capacity;
    }

    Number(const Number& n) : size(n.size), capacity(n.capacity) {
        data = new char[capacity];
        std::copy(n.data, n.data + size, data);
    }

    Number(const std::string& str) {
        size = (str.size() + 1) / 2;
        capacity = size;
        data = new char[capacity];

        for (std::size_t i = 0; i < size; ++i) {
            int digit = 0;
            if (str.size() - 2 * i - 1 >= 0) {
                digit += (str[str.size() - 2 * i - 1] - '0') * 10;
            }
            if (str.size() - 2 * i >= 0) {
                digit += (str[str.size() - 2 * i] - '0');
            }
            data[i] = digit;
        }
    }

    Number& operator=(const Number& n) {
        if (this != &n) {
            delete[] data;
            size = n.size;
            capacity = n.capacity;
            data = new char[capacity];
            std::copy(n.data, n.data + size, data);
        }
        return *this;
    }

    ~Number() {
        delete[] data;
    }

    Number operator+(const Number& n) const {
        Number result;
        result.size = std::max(size, n.size);
        result.capacity = result.size + 1;
        result.data = new char[result.capacity];

        int carry = 0;
        for (std::size_t i = 0; i < result.size; ++i) {
            int sum = (i < size ? data[i] : 0) + (i < n.size ? n.data[i] : 0) + carry;
            result.data[i] = sum % base;
            carry = sum / base;
        }
        if (carry > 0) {
            result.data[result.size++] = carry;
        }
        return result;
    }

    Number& operator+=(const Number& n) {
        *this = *this + n;
        return *this;
    }

    bool isEven() const {
        return data[0] % 2 == 0;
    }

    Number operator*(const Number& n) const {
        Number result;
        result.size = size + n.size;
        result.capacity = result.size;
        result.data = new char[result.capacity];
        std::fill(result.data, result.data + result.capacity, 0);

        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < n.size; ++j) {
                result.data[i + j] += data[i] * n.data[j];
                result.data[i + j + 1] += result.data[i + j] / base;
                result.data[i + j] %= base;
            }
        }
        while (result.size > 1 && result.data[result.size - 1] == 0) {
            --result.size;
        }
        return result;
    }

    static Number factorial(int n) {
        Number result = 1;
        for (int i = 2; i <= n; ++i) {
            result = result * Number(i);
        }
        return result;
    }

    static Number fibonacci(int n) {
        if (n == 0) return Number(0);
        if (n == 1) return Number(1);
        Number a = 0;
        Number b = 1;
        Number result;
        for (int i = 2; i <= n; ++i) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    stream << static_cast<int>(num.data[num.size - 1]);
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);
    return stream;
}