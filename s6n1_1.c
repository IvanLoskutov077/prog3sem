#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t* num = (size_t*)malloc(sizeof(size_t));
    if (num == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *num = 42;
    printf("Number: %zu\n", *num);
    free(num);
    return 0;
}
