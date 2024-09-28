#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];
    scanf("%s", word1);

    scanf("%s", word2);

    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int maxLen = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < maxLen; i++) {
        if (i < len1) {
            printf("%c", word1[i]);
        }
        if (i < len2) {
            printf("%c", word2[i]);
        }
    }

    printf("\n");

    return 0;
}