#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::multiset<int> numbers;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        numbers.insert(num);
    }

    for (const int& num : numbers) {
        std::cout << num << " ";
    }
}