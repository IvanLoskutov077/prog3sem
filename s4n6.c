#include <stdio.h>

void set_characters(const char* begin, const char* end, char c) {
    char* p = (char*)begin;
    while (p < end) {
        *p = c;
        p++;
    }
}

int main() {
    char s[] = "Sapere Aude";
    set_characters(&s[2], &s[8], 'b');
    printf("%s\n", s);
    set_characters(s, &s[4], 'a');
    printf("%s\n", s);

    return 0;
}