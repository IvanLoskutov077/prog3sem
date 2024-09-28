#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt_caesar(FILE *input, FILE *output, int key) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + key) % 26 + base;
        }
        fputc(ch, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int key = atoi(argv[3]);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    encrypt_caesar(input, output, key);

    fclose(input);
    fclose(output);

    return 0;
}