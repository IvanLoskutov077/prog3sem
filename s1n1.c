#include <stdio.h>
int main()
{
int a;
scanf("%i", &a);
if (a % 2 ==0 && (a>-1 && a<21 || 100<a && a<200))
    {
    printf("yes");
    }
else
    {
        printf("no");
    }
}
