#include <stdio.h>

long fact(long k) {
    long res = 1;
    for (int i = 1; i <= k; ++i) res *= i;
    return res;
}

int main(void) {
    long k;
    scanf("%ld", &k);
    printf("%ld\n", fact(k));
}