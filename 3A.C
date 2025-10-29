#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fill matrix with random values [0–9]
void fillMatrix(int n, int **mat) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = rand() % 10;
}

// Standard iterative matrix multiplication
void multiplyIterative(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    srand(time(NULL));
    FILE *file = fopen("iterative_times.csv", "w");
    fprintf(file, "Size,Time\n");

    int sizes[] = {8, 16, 32, 64, 128, 256, 512, 1024};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];

        // Allocate memory for matrices
        int **A = malloc(n * sizeof(int *));
        int **B = malloc(n * sizeof(int *));
        int **C = malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            A[i] = malloc(n * sizeof(int));
            B[i] = malloc(n * sizeof(int));
            C[i] = malloc(n * sizeof(int));
        }

        fillMatrix(n, A);
        fillMatrix(n, B);

        clock_t start = clock();
        multiplyIterative(n, A, B, C);
        clock_t end = clock();

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%d,%f\n", n, timeTaken);
        printf("Iterative (%dx%d): %f seconds\n", n, n, timeTaken);
        printf("n = %d completed\n", n);

        // Free memory
        for (int i = 0; i < n; i++) {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }
        free(A);
        free(B);
        free(C);
    }

    fclose(file);
    printf("Iterative results written to iterative_times.csv\n");
    return 0;
}
