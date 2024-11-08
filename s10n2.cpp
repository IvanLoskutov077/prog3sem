#include <iostream>

void cube(int &num) {
    num = num * num * num;
}

int main() {
    int a = 5;
    cube(a);
    std::cout << a << std::endl;
    return 0;
}