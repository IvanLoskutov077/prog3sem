#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

class Integer
{
private:
    static const int base = 100;

    std::vector<int> data;

public:
    Integer() : data(1, 0) {}

    Integer(int a) {
        while (a > 0) {
            data.push_back(a % base);
            a /= base;
        }
        if (data.empty()) {
            data.push_back(0);
        }
    }

    Integer(const Integer& n) : data(n.data) {}

    Integer(const std::string& str) {
        for (std::size_t i = 0; i < str.size(); i += 2) {
            int digit = 0;
            if (i + 1 < str.size()) {
                digit += (str[str.size() - i - 2] - '0') * 10;
            }
            digit += (str[str.size() - i - 1] - '0');
            data.push_back(digit);
        }
    }

    Integer& operator=(const Integer& n) {
        if (this != &n) {
            data = n.data;
        }
        return *this;
    }

    Integer operator+(const Integer& n) const {
        Integer result;
        std::size_t size = std::max(data.size(), n.data.size());
        result.data.resize(size);

        int carry = 0;
        for (std::size_t i = 0; i < size; ++i) {
            int sum = (i < data.size() ? data[i] : 0) + (i < n.data.size() ? n.data[i] : 0) + carry;
            result.data[i] = sum % base;
            carry = sum / base;
        }
        if (carry > 0) {
            result.data.push_back(carry);
        }
        return result;
    }

    Integer& operator+=(const Integer& n) {
        *this = *this + n;
        return *this;
    }

    bool isEven() const {
        return data[0] % 2 == 0;
    }

    Integer operator*(const Integer& n) const {
        Integer result;
        result.data.resize(data.size() + n.data.size());
        std::fill(result.data.begin(), result.data.end(), 0);

        for (std::size_t i = 0; i < data.size(); ++i) {
            for (std::size_t j = 0; j < n.data.size(); ++j) {
                result.data[i + j] += data[i] * n.data[j];
                result.data[i + j + 1] += result.data[i + j] / base;
                result.data[i + j] %= base;
            }
        }
        while (result.data.size() > 1 && result.data.back() == 0) {
            result.data.pop_back();
        }
        return result;
    }

    static Integer factorial(int n) {
        Integer result = 1;
        for (int i = 2; i <= n; ++i) {
            result = result * Integer(i);
        }
        return result;
    }

    static Integer fibonacci(int n) {
        if (n == 0) return Integer(0);
        if (n == 1) return Integer(1);
        Integer a = 0;
        Integer b = 1;
        Integer result;
        for (int i = 2; i <= n; ++i) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Integer& num);
};

std::ostream& operator<<(std::ostream& stream, const Integer& num)
{
    stream << num.data.back();
    for (std::size_t i = 0; i < num.data.size() - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << num.data[num.data.size() - 2 - i];
    return stream;
}