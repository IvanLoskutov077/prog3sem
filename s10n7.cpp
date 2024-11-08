#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits) {
    numLetters = 0;
    numDigits = 0;

    for (char ch : str) {
        if (std::isalpha(ch)) {
            numLetters++;
        } else if (std::isdigit(ch)) {
            numDigits++;
        }
    }
}

int main() {
    std::string str = "Hello World! 123";
    int numLetters = 0;
    int numDigits = 0;

    countLetters(str, numLetters, numDigits);

    std::cout << "Number of letters: " << numLetters << std::endl;
    std::cout << "Number of digits: " << numDigits << std::endl;

    return 0;
}