#include <stdio.h>
#include <string.h>

void safe_strcpy(char dest[], size_t dest_size, const char src[]) {
    size_t i;
    for (i = 0; i < dest_size - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[dest_size - 1] = '\0';
}

int main() {
    char a[10];
    char b[50];
    scanf("%s", a);
    scanf("%s", b);

    printf("Before \"%s\"\n", a);
    safe_strcpy(a, 14, b);
    printf("After \"%s\"\n", a);

    return 0;
}