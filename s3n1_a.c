#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);

    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        printf("Letter\n");
    } else if (ch >= '0' && ch <= '9') {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }

    return 0;
}