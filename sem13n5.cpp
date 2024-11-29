#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>

int sum_numbers_in_brackets(const std::string& input) {
    if (input.empty() || input.front() != '[' || input.back() != ']') {
        throw std::invalid_argument("Invalid input format");
    }

    std::stringstream ss(input.substr(1, input.size() - 2));
    std::string item;
    int sum = 0;
    bool has_number = false;

    while (std::getline(ss, item, ',')) {
        std::stringstream item_ss(item);
        int number;
        if (!(item_ss >> number) || !item_ss.eof()) {
            throw std::invalid_argument("Invalid number format");
        }
        sum += number;
        has_number = true;
    }

    if (!has_number) {
        return 0;
    }

    return sum;
}

int main() {
    std::vector<std::string> test_cases = {
        "[10, 20, 30, 40, 50]",
        "[4, 8, 15, 16, 23, 42]",
        "[20]",
        "[]",
        "[1, 2, 3]",
        "[100, -50, 25]",
        "[invalid]",
        "[1, 2, three]",
        "10, 20, 30, 40, 50]",
        "[10, 20, 30, 40, 50"
    };

    for (const auto& test_case : test_cases) {
        try {
            int result = sum_numbers_in_brackets(test_case);
            std::cout << "Input: " << test_case << " -> Result: " << result << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Input: " << test_case << " -> Exception: " << e.what() << std::endl;
        }
    }

    return 0;
}