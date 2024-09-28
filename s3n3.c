#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrom(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        while (left < right && !isalpha(str[left])) {
            left++;
        }
        while (left < right && !isalpha(str[right])) {
            right--;
        }

        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

int main() {
    char str[100];

    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;

    if (is_palindrom(str)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}