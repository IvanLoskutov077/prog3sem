#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

template <typename Container>
std::vector<std::pair<typename Container::value_type, typename Container::value_type>> pairElements(const Container& container) {
    std::vector<std::pair<typename Container::value_type, typename Container::value_type>> result;
    auto it = container.begin();
    while (it != container.end()) {
        auto next = std::next(it);
        if (next != container.end()) {
            result.emplace_back(*it, *next);
            it = std::next(next);
        } else {
            result.emplace_back(*it, typename Container::value_type());
            break;
        }
    }
    return result;
}

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    auto vecPairs = pairElements(vec);
    for (const auto& pair : vecPairs) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;

    std::list<std::string> lst = {"cat", "dog", "mouse", "lion"};
    auto lstPairs = pairElements(lst);
    for (const auto& pair : lstPairs) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;

    std::string str = "Hello";
    auto strPairs = pairElements(str);
    for (const auto& pair : strPairs) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;

    return 0;
}