#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <word> <count>\n", argv[0]);
        return 1;
    }

    char *word = argv[1];
    int count = atoi(argv[2]);

    if (count <= 0) {
        fprintf(stderr, "Count must be a positive num.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("%s ", word);
    }
    printf("\n");

    return 0;
}