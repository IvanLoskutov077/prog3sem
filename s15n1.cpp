#include <iostream>
#include <list>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::list<int> warriors;
    for (int i = 1; i <= n; ++i) {
        warriors.push_back(i);
    }

    std::vector<int> eliminationOrder;
    auto it = warriors.begin();

    while (warriors.size() > 1) {
        for (int i = 1; i < m; ++i) {
            ++it;
            if (it == warriors.end()) {
                it = warriors.begin();
            }
        }
        eliminationOrder.push_back(*it);
        it = warriors.erase(it);
        if (it == warriors.end()) {
            it = warriors.begin();
        }
    }

    for (int num : eliminationOrder) {
        std::cout << num << " ";
    }

    std::cout << "\n" << warriors.front() << std::endl;

    return 0;
}