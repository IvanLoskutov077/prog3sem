#include <stdio.h>

int main() {
    int a[10];
    char k[10];
    
    printf("Размеры типов данных в языке C:\n");
    printf("Размер типа char: %zu байт\n", sizeof(char));
    printf("Размер типа short: %zu байт\n", sizeof(short));
    printf("Размер типа int: %zu байт\n", sizeof(int));
    printf("Размер типа long long: %zu байт\n", sizeof(long long));
    printf("Размер типа float: %zu байт\n", sizeof(float));
    printf("Размер типа double: %zu байт\n", sizeof(double));
    printf("Размер типа long: %zu байт\n", sizeof(size_t));
    printf("Размер типа int[10]: %zu байт\n", sizeof(a));
    printf("Размер типа char[10]: %zu байт\n", sizeof(k));

    return 0;
}