#include <stdio.h>

void alice(int n);

void bob(int n) {
    if (n == 1) {
        printf("Bob: %d\n", n);
        return;
    }

    if (n % 2 == 0) {
        printf("Bob: %d\n", n);
        bob(n / 2);
    } else {
        printf("Bob: %d\n", n);
        alice(n);
    }
}

void alice(int n) {
    n = n * 3 + 1;
    printf("Alice: %d\n", n);
    bob(n);
}

int main() {
    int start = 13;
    
    alice(start);
    
    return 0;
}
