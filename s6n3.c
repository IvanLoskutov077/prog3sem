#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return 1;
    }

    const char* input_filename = argv[1];
    const char* output_filename = argv[2];

    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        return 1;
    }

    char** lines = NULL;
    int line_count = 0;
    int capacity = 10;
    lines = (char**)malloc(capacity * sizeof(char*));
    if (lines == NULL) {
        fclose(input_file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file)) {
        if (line_count >= capacity) {
            capacity *= 2;
            lines = (char**)realloc(lines, capacity * sizeof(char*));
            if (lines == NULL) {
                fclose(input_file);
                return 1;
            }
        }
        lines[line_count] = strdup(buffer);
        if (lines[line_count] == NULL) {
            fclose(input_file);
            return 1;
        }
        line_count++;
    }
    fclose(input_file);

    qsort(lines, line_count, sizeof(char*), compare_strings);

    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        return 1;
    }

    for (int i = 0; i < line_count; i++) {
        fprintf(output_file, "%s", lines[i]);
        free(lines[i]);
    }
    fclose(output_file);

    free(lines);

    return 0;
}
