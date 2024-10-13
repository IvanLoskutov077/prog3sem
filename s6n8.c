#include <stdio.h>

int adder(int num) {
    static int sum = 0;
    sum += num;
    return sum;
}

int main() {
    printf("%i\n", adder(10)); 
    printf("%i\n", adder(15));
    printf("%i\n", adder(70)); 
    return 0;
}
