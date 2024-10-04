#include <stdio.h>

void cube(float* px) {
    *px = (*px) * (*px) * (*px);
}

int main() {
    float a;
    scanf("%f", &a);
    printf("%f\n", a);

    cube(&a);

    printf("%f\n", a);

    return 0;
}