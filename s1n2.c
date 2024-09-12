#include <stdio.h>
int main()
{
    int a;
    int b;
    int c;
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);
    if ((c == b + 1 && b == a + 1) || (a == b +1 && b == c+1))
        printf("consecutive ");
    if (a<b && b<c)
        printf("increasing ");
    else if (a>b && b>c)
        printf("decreasing ");
    else if (a==b && b==c)
        printf("equal ");
    else
        printf("none ");
}