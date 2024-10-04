#include <stdio.h>
#include <math.h>

#define EPS 1e-10

int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    if (fabs(a) < EPS) {
        if (fabs(b) < EPS) {
            if (fabs(c) < EPS) {
                return -1;
            } else {
                return 0;
            }
        } else {
            *px1 = -c / b;
            return 1;
        }
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < -EPS) {
        return 0;
    } else if (fabs(discriminant) < EPS) {
        *px1 = -b / (2 * a);
        return 1;
    } else {
        *px1 = (-b + sqrt(discriminant)) / (2 * a);
        *px2 = (-b - sqrt(discriminant)) / (2 * a);
        return 2;
    }
}

int main() {
    double a = 1.0, b = -3.0, c = 2.0;
    double x1, x2;
    int result = solve_quadratic(a, b, c, &x1, &x2);

    if (result == 0) {
        printf("Нет корней.\n");
    } else if (result == 1) {
        printf("x = %f\n", x1);
    } else if (result == 2) {
        printf("x1 = %f, x2 = %f\n", x1, x2);
    } else {
        printf("Бесконечное количество решений.\n");
    }

    return 0;
}