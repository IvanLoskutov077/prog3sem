#include <stdio.h>

float yearfrac(int year, int day) {
    if (year % 4 == 0) return (float)day / 366.0;
    return (float)day / 365.0;
}

int main(void) {
    int year, day;
    scanf("%d %d", &year, &day);
    printf("%f", yearfrac(year, day));
}