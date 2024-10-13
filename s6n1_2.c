#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* str = (char*)malloc(6 * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    strcpy(str, "hello");
    printf("String: %s\n", str);
    free(str);
    return 0;
}
