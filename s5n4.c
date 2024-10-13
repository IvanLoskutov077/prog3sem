#include <stdio.h>
#include <stddef.h>

struct cat {
    char x;
    size_t y;
};

struct dog {
    size_t y;
    char x;
};

struct mouse {
    char x;
    char y;
    size_t z;
};

struct rat {
    char x;
    size_t z;
    char y;
};

struct fox {
    char x;
    struct mouse y;
};

int main() {
    // Вывод размеров и выравниваний для различных типов
    printf("Type: char\n");
    printf("Size: %zu bytes\n", sizeof(char));
    printf("Alignment: %zu bytes\n\n", _Alignof(char));

    printf("Type: int\n");
    printf("Size: %zu bytes\n", sizeof(int));
    printf("Alignment: %zu bytes\n\n", _Alignof(int));

    printf("Type: size_t\n");
    printf("Size: %zu bytes\n", sizeof(size_t));
    printf("Alignment: %zu bytes\n\n", _Alignof(size_t));

    printf("Type: int[10]\n");
    printf("Size: %zu bytes\n", sizeof(int[10]));
    printf("Alignment: %zu bytes\n\n", _Alignof(int[10]));

    printf("Type: int*\n");
    printf("Size: %zu bytes\n", sizeof(int*));
    printf("Alignment: %zu bytes\n\n", _Alignof(int*));

    printf("Type: struct cat\n");
    printf("Size: %zu bytes\n", sizeof(struct cat));
    printf("Alignment: %zu bytes\n\n", _Alignof(struct cat));

    printf("Type: struct dog\n");
    printf("Size: %zu bytes\n", sizeof(struct dog));
    printf("Alignment: %zu bytes\n\n", _Alignof(struct dog));

    printf("Type: struct mouse\n");
    printf("Size: %zu bytes\n", sizeof(struct mouse));
    printf("Alignment: %zu bytes\n\n", _Alignof(struct mouse));

    printf("Type: struct rat\n");
    printf("Size: %zu bytes\n", sizeof(struct rat));
    printf("Alignment: %zu bytes\n\n", _Alignof(struct rat));

    printf("Type: struct fox\n");
    printf("Size: %zu bytes\n", sizeof(struct fox));
    printf("Alignment: %zu bytes\n\n", _Alignof(struct fox));

    return 0;
}
