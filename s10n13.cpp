#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& v) {
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::string> prefixes(const std::string& str) {
    std::vector<std::string> result;
    std::string pr_sm = "";
    for (std::size_t i = 0; i < str.size(); ++i) {
        pr_sm += str[i];
        result.push_back(pr_sm);
    }
    return result;
}

int main() {
    std::vector<std::string> v = prefixes("Mouse");
    print(v);
    return 0;
}