#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if (isalpha(ch)) {
        printf("Letter\n");
    } else if (isdigit(ch)) {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }

    return 0;
}