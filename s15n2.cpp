#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::set<int> numbers;
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        numbers.insert(k);
    }

    for (const int& num : numbers) {
        std::cout << num << " ";
    }
}