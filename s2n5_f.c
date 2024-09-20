#include <stdio.h>

void print_binary(int n) {
    if (n == 0) {
        return;
    }
    print_binary(n / 2);
    
    printf("%d", n % 2);
}

int main() {
    int number;
    scanf("%d", &number);
    if (number == 0) {
        printf("0");
    } 
    else {
        print_binary(number);
    }
    return 0;
}