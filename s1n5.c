#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int cnt = 1;
    int mx = -1;
    printf("%d ", n);
    while (n != 1) {
        if (n % 2 != 0) {
            n = 3 * n + 1;
            printf("%d ", n);
            cnt++;
            if (n > mx) mx = n;
        }
        else {
            n /= 2;
            printf("%d ", n);
            cnt++;
            if (n > mx) mx = n;
        }
    }
    printf("\nLength: %d; Max: %d\n", cnt, mx);
}