#include <iostream>

template<typename T, T Mod>
class Modular {
private:
    T value;

    T mod(T x) const {
        return (x % Mod + Mod) % Mod;
    }

public:
    Modular(T val = 0) : value(mod(val)) {}

    Modular(const Modular& other) : value(other.value) {}

    Modular& operator=(const Modular& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    Modular operator+(const Modular& other) const {
        return Modular(mod(value + other.value));
    }

    Modular operator-(const Modular& other) const {
        return Modular(mod(value - other.value));
    }

    Modular operator*(const Modular& other) const {
        return Modular(mod(value * other.value));
    }

    Modular operator+(T other) const {
        return Modular(mod(value + other));
    }

    Modular operator-(T other) const {
        return Modular(mod(value - other));
    }

    Modular operator*(T other) const {
        return Modular(mod(value * other));
    }

    Modular operator-() const {
        return Modular(mod(-value));
    }

    friend std::ostream& operator<<(std::ostream& os, const Modular& m) {
        os << m.value;
        return os;
    }

    template<typename U, U OtherMod>
    Modular(const Modular<U, OtherMod>& other) : value(mod(static_cast<T>(other.getValue()))) {}

    T getValue() const {
        return value;
    }
};

int main() {
    Modular<int, 7> a(10);
    std::cout << a << std::endl; // Напечатает 3
    a = (a + 8) * 4;
    std::cout << a << std::endl; // Напечатает 2

    Modular<int, 7> b(a);
    b = b + 2;
    a = a - b;
    std::cout << a << std::endl; // Напечатает 5

    Modular<short, 3> c(a);
    std::cout << c << std::endl; // Напечатает 2

    return 0;
}