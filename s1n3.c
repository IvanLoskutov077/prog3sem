#include <stdio.h>
int main()
{
int a;
int i=1;
scanf("%i", &a);
while (i<(a+1))
{
    printf("%i -> %i -> %i\n", i, i*i, i*i*i);
    i++;
}
}
