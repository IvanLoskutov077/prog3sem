#include <stdio.h>
#include <stdlib.h>

void mult2(int* p, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        p[i] *= 2;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mult2(arr, n);

    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}