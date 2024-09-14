#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int mx = -1, ans;
    for (int i = a; i <= b; ++i) {
        int cnt = 1, n = i;
        while (n != 1) {
            if (n % 2 != 0) {
                n = 3 * n + 1;
                cnt++;
            }
            else {
                n /= 2;
                cnt++;
            }
        }
        if (cnt > mx) {
            mx = cnt;
            ans = i;
        }
    }
    printf("%d %d", ans, mx);
}