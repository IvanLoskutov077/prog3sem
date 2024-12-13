#include <iostream>
#include <vector>
#include <array>
#include <string>

template<typename T1, typename T2>
bool hasMoreElements(const T1& container1, const T2& container2) {
    return container1.size() > container2.size();
}

int main() {
    std::vector<int> a {10, 20, 30, 40, 50};
    std::string b = "Cat";
    std::string c = "Elephant";
    std::array<int, 3> d {10, 20, 30};

    std::cout << hasMoreElements(a, b) << std::endl;  // Должно напечатать 1
    std::cout << hasMoreElements(a, c) << std::endl;  // Должно напечатать 0
    std::cout << hasMoreElements(a, d) << std::endl;  // Должно напечатать 1

    return 0;
}