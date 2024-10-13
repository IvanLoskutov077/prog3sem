#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** strings = (char**)malloc(4 * sizeof(char*));
    if (!strings) {
        return NULL;
    }

    strings[0] = strdup("hello");
    strings[1] = strdup("world");
    strings[2] = strdup("foo");
    strings[3] = NULL;

    return strings;
}

void print_strings(FILE* stream, char** string_array) {
    for (size_t i = 0; string_array[i] != NULL; ++i) {
        fprintf(stream, "%s\n", string_array[i]);
    }
}

char** load_lines(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    int line_count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
    }
    line_count++;

    char** strings = (char**)malloc((line_count + 1) * sizeof(char*));
    if (!strings) {
        fclose(file);
        return NULL;
    }

    size_t* lengths = (size_t*)malloc(line_count * sizeof(size_t));
    if (!lengths) {
        free(strings);
        fclose(file);
        return NULL;
    }

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < line_count; ++i) {
        lengths[i] = 0;
        while ((ch = fgetc(file)) != EOF && ch != '\n') {
            lengths[i]++;
        }
    }

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < line_count; ++i) {
        strings[i] = (char*)malloc((lengths[i] + 1) * sizeof(char));
        if (!strings[i]) {
            for (int j = 0; j < i; ++j) {
                free(strings[j]);
            }
            free(strings);
            free(lengths);
            fclose(file);
            return NULL;
        }
        fgets(strings[i], lengths[i] + 1, file);
        strings[i][strcspn(strings[i], "\n")] = 0;
    }

    free(lengths);

    strings[line_count] = NULL;

    fclose(file);
    return strings;
}

void destroy_strings(char*** p_string_array) {
    if (!p_string_array || !*p_string_array) {
        return;
    }

    char** strings = *p_string_array;
    for (size_t i = 0; strings[i] != NULL; ++i) {
        free(strings[i]);
    }
    free(strings);
    *p_string_array = NULL;
}

void sort_strings(char** words) {
    size_t count = 0;
    while (words[count] != NULL) {
        count++;
    }

    for (size_t i = 0; i < count - 1; ++i) {
        for (size_t j = 0; j < count - i - 1; ++j) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}


int main() {
    char** strings = get_test_strings();
    print_strings(stdout, strings);

    destroy_strings(&strings);

    strings = load_lines("three_little_pigs.txt");
    print_strings(stdout, strings);

    sort_strings(strings);
    print_strings(stdout, strings);

    destroy_strings(&strings);

    return 0;
}
