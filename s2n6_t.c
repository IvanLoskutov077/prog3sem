#define _USE_MATH_DEFINES
#include <math.h>

#include <stdio.h>

const double g = 7;
const double p[] = {
    0.99999999999980993, 676.5203681218851, -1259.1392167224028,
    771.32342877765313, -176.61502916214059, 12.507343278686905,
    -0.13857109526572012, 9.9843695780195716e-6, 1.5056327351493116e-7
};

double gamma(double x) {
    if (x < 0.5) {
        return M_PI / (sin(M_PI * x) * gamma(1 - x));
    }

    x -= 1;
    double a = 0.99999999999980993;
    for (int i = 1; i < g + 2; i++) {
        a += p[i] / (x + i);
    }

    double t = x + g + 0.5;
    return sqrt(2 * M_PI) * pow(t, x + 0.5) * exp(-t) * a;
}

int main() {
    double x;
    scanf("%lf", &x);
    double result = gamma(x);
    printf("%lf\n", result);
    return 0;
}