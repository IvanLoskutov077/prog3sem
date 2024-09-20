#include <stdio.h>

void print_even(int a, int b) {

    if (a % 2 != 0) {
        a++;
    }

    for (int i = a; i <= b; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    print_even(3, 15);
    print_even(10, 20);
    return 0;
}
