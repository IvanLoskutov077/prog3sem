#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> numberCount;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        numberCount[num]++;
    }

    for (const auto& pair : numberCount) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}