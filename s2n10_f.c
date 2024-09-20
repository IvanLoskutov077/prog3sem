#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void transpose(float A[MAX][MAX], int n) {
    float temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

void print(float A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *inputFile = fopen("files/matA.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    int n;
    float A[MAX][MAX];

    fscanf(inputFile, "%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(inputFile, "%f", &A[i][j]);
        }
    }

    fclose(inputFile);

    transpose(A, n);

    print(A, n);

    FILE *outputFile = fopen("result.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    fprintf(outputFile, "%d\n", n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(outputFile, "%f ", A[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    return 0;
}