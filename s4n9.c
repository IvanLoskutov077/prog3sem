#include <stdio.h>
#include <string.h>

char* strmax(char** strings, size_t n) {
    if (n == 0) {
        return NULL;
    }

    char* max_string = strings[0];

    for (size_t i = 1; i < n; ++i) {
        if (strcmp(strings[i], max_string) > 0) {
            max_string = strings[i];
        }
    }

    return max_string;
}

int main() {
    char a[] = "Cat";
    char b[] = "Mouse";
    char c[] = "Wolf";
    char d[] = "Kangaroo";
    char e[] = "Elephant";

    char* animals[5] = {a, b, c, d, e};
    char* x = strmax(animals, 5);
    printf("%s\n", x);

    return 0;
}