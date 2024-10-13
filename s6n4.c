#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* get_geometric_progression(float a, float r, int n) {
    float* progression = (float*)malloc(n * sizeof(float));
    if (progression == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; ++i) {
        progression[i] = a * pow(r, i);
    }

    return progression;
}

int main() {
    int n = 10;
    float a = 3.0;
    float r = 3.0;

    float* progression = get_geometric_progression(a, r, n);
    if (progression == NULL) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("%f\n", progression[i]);
    }

    free(progression);

    return 0;
}
