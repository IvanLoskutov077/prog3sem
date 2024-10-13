#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char** str_ptr = (char**)malloc(sizeof(char*));
    if (str_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *str_ptr = (char*)malloc(6 * sizeof(char));
    if (*str_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(str_ptr);
        return 1;
    }
    strcpy(*str_ptr, "hello");
    printf("String: %s\n", *str_ptr);
    free(*str_ptr);
    free(str_ptr);
    return 0;
}
