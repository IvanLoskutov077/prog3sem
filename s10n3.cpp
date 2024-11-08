#include <iostream>

void swap(int &num, int &num2) {
    int a = num;
    num = num2;
    num2 = a;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << a << ' ' << b << std::endl;

    swap(a, b);
    std::cout << a << ' ' << b << std::endl;
    return 0;
}