#include <stdio.h>

int main(void) {
    int n;
    double sm = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) sm += (double)1 / (2 * i - 1);
        else sm -= (double)1 / (2 * i - 1);
    }
    printf("%lf\n", 4 * sm);
}