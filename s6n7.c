#include <stdio.h>
#include <math.h>

int is_negative(int num) {
    return num < 0;
}

int is_even(int num) {
    return num % 2 == 0;
}

int is_square(int num) {
    int root = (int)sqrt(num);
    return root * root == num;
}

size_t count_if(int* arr, size_t size, int (*predicate)(int)) {
    size_t count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (predicate(arr[i])) {
            ++count;
        }
    }
    return count;
}

int main() {
    int a[] = {89, 81, 28, 52, 44, 16, -64, 49, 52, -79};

    printf("%zu\n", count_if(a, 10, is_negative)); 
    printf("%zu\n", count_if(a, 10, is_even));
    printf("%zu\n", count_if(a, 10, is_square));

    return 0;
}
