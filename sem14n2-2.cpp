#include <iostream>
#include <string>

template<typename T>
T triple(const T& x) {
    return 3 * x;
}

std::string operator*(int n, const std::string& s) {
    std::string result;
    for (int i = 0; i < n; ++i) {
        result += s;
    }
    return result;
}

int main() {
    int a = 10;
    std::cout << triple(a) << std::endl;  // Сработает, напечатает 30

    std::string b = "Cat";
    std::cout << triple(b) << std::endl;  // Напечатает CatCatCat

    return 0;
}