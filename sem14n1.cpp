#include <iostream>

template <typename T>
T cube(T value) {
    return value * value * value;
}

int main() {
    auto a = cube(5);
    std::cout << a << " " << sizeof(a) << std::endl;  // Должен напечатать  125 4

    auto b = cube(5.0);
    std::cout << b << " " << sizeof(b) << std::endl;  // Должен напечатать  125.0 8

    char x = 5;
    auto c = cube(x);
    std::cout << c << " " << sizeof(c) << std::endl;  // Должен напечатать  125 1

    return 0;
}