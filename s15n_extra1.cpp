#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> stack;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    std::string input;
    std::cin >> input;

    if (isValid(input)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}