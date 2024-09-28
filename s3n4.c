#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char* str, int k) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char base = isupper(str[i]) ? 'A' : 'a';
            str[i] = (str[i] - base + k) % 26 + base;
        }
    }
}

int main() {
    char str[100];
    int k;

    scanf("%d", &k);
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;

    encrypt(str, k);

    printf("%s\n", str);

    return 0;
}