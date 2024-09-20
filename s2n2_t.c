#include <stdio.h>

unsigned long long fact(unsigned long long k) {
    unsigned long long res = 1;
    for (int i = 1; i <= k; ++i) res *= i;
    return res;
}

int main(void) {
    unsigned long long k, n;
    scanf("%llu %llu", &n, &k);
    printf("%llu\n", fact(n) / fact(n - k));
}