#include <iostream>
#include <set>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::set<int> cutPoints;
    std::multiset<int> lengths;

    cutPoints.insert(0);
    cutPoints.insert(n);

    lengths.insert(n);

    for (int i = 0; i < k; ++i) {
        int cut;
        std::cin >> cut;
        cutPoints.insert(cut);

        auto it = cutPoints.find(cut);
        int prevCut = *std::prev(it);
        int nextCut = *std::next(it);

        lengths.erase(lengths.find(nextCut - prevCut));

        lengths.insert(cut - prevCut);
        lengths.insert(nextCut - cut);

        int maxLength = *lengths.rbegin();
        std::cout << maxLength << " ";
    }

    return 0;
}