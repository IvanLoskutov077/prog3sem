#include <stdio.h>
#include <math.h>

int main() {
    long double x1, y1, r1;
    long double x2, y2, r2;
    scanf("%Lf %Lf %Lf", &x1, &y1, &r1);
    scanf("%Lf %Lf %Lf", &x2, &y2, &r2);

    long double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    long double sum_of_radii = r1 + r2;
    long double diff_of_radii = fabs(r1 - r2);
    
    if (distance > sum_of_radii) {
        printf("Do not intersect\n");
    } 
    else if (fabs(distance - sum_of_radii) <= 1e-5 || fabs(distance - diff_of_radii) <= 1e-5) {
        printf("Touch\n");
    } 
    else if (distance > diff_of_radii) {
        printf("Intersect\n");
    } 
    else {
        printf("Do not intersect\n");
    }

    return 0;
}