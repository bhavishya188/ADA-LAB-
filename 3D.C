#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---------- Utility Functions ----------
int** allocateMatrix(int n) {
    int *mat = (int)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        mat[i] = (int*)calloc(n, sizeof(int));
    return mat;
}

void freeMatrix(int **mat, int n) {
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}

void generateRandomMatrix(int **mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = rand() % 10;
}

void addMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// ---------- Iterative ----------
void multiplyIterative(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// ---------- Recursive ----------
void multiplyRecursive(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int k = n / 2;
    int **A11 = allocateMatrix(k), **A12 = allocateMatrix(k), **A21 = allocateMatrix(k), **A22 = allocateMatrix(k);
    int **B11 = allocateMatrix(k), **B12 = allocateMatrix(k), **B21 = allocateMatrix(k), **B22 = allocateMatrix(k);
    int **C11 = allocateMatrix(k), **C12 = allocateMatrix(k), **C21 = allocateMatrix(k), **C22 = allocateMatrix(k);
    int **M1 = allocateMatrix(k), **M2 = allocateMatrix(k);

    // Split A and B
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }

    // Compute submatrices
    multiplyRecursive(A11, B11, M1, k);
    multiplyRecursive(A12, B21, M2, k);
    addMatrix(M1, M2, C11, k);

    multiplyRecursive(A11, B12, M1, k);
    multiplyRecursive(A12, B22, M2, k);
    addMatrix(M1, M2, C12, k);

    multiplyRecursive(A21, B11, M1, k);
    multiplyRecursive(A22, B21, M2, k);
    addMatrix(M1, M2, C21, k);

    multiplyRecursive(A21, B12, M1, k);
    multiplyRecursive(A22, B22, M2, k);
    addMatrix(M1, M2, C22, k);

    // Merge into C
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[i+k][j] = C21[i][j];
            C[i+k][j+k] = C22[i][j];
        }

    // Free
    freeMatrix(A11, k); freeMatrix(A12, k); freeMatrix(A21, k); freeMatrix(A22, k);
    freeMatrix(B11, k); freeMatrix(B12, k); freeMatrix(B21, k); freeMatrix(B22, k);
    freeMatrix(C11, k); freeMatrix(C12, k); freeMatrix(C21, k); freeMatrix(C22, k);
    freeMatrix(M1, k); freeMatrix(M2, k);
}

// ---------- Strassen ----------
void strassen(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int k = n / 2;
    int **A11 = allocateMatrix(k), **A12 = allocateMatrix(k), **A21 = allocateMatrix(k), **A22 = allocateMatrix(k);
    int **B11 = allocateMatrix(k), **B12 = allocateMatrix(k), **B21 = allocateMatrix(k), **B22 = allocateMatrix(k);
    int **C11 = allocateMatrix(k), **C12 = allocateMatrix(k), **C21 = allocateMatrix(k), **C22 = allocateMatrix(k);

    // Temporary matrices
    int **M1 = allocateMatrix(k), **M2 = allocateMatrix(k), **M3 = allocateMatrix(k), **M4 = allocateMatrix(k),
        **M5 = allocateMatrix(k), **M6 = allocateMatrix(k), **M7 = allocateMatrix(k);
    int **T1 = allocateMatrix(k), **T2 = allocateMatrix(k);

    // Split A and B
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }

    // Strassen's 7 multiplications
    addMatrix(A11, A22, T1, k);
    addMatrix(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    addMatrix(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    subMatrix(B12, B22, T1, k);
    strassen(A11, T1, M3, k);

    subMatrix(B21, B11, T1, k);
    strassen(A22, T1, M4, k);

    addMatrix(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    subMatrix(A21, A11, T1, k);
    addMatrix(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    subMatrix(A12, A22, T1, k);
    addMatrix(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    // Compute C submatrices
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }

    // Merge into C
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[i+k][j] = C21[i][j];
            C[i+k][j+k] = C22[i][j];
        }

    // Free memory
    freeMatrix(A11, k); freeMatrix(A12, k); freeMatrix(A21, k); freeMatrix(A22, k);
    freeMatrix(B11, k); freeMatrix(B12, k); freeMatrix(B21, k); freeMatrix(B22, k);
    freeMatrix(C11, k); freeMatrix(C12, k); freeMatrix(C21, k); freeMatrix(C22, k);
    freeMatrix(M1, k); freeMatrix(M2, k); freeMatrix(M3, k); freeMatrix(M4, k);
    freeMatrix(M5, k); freeMatrix(M6, k); freeMatrix(M7, k);
    freeMatrix(T1, k); freeMatrix(T2, k);
}

// ---------- Timer ----------
double getTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// ---------- Main ----------
int main() {
    srand(time(0));
    int sizes[] = {2, 4, 8, 16, 32}; // 2^n sizes
    int numSizes = sizeof(sizes)/sizeof(sizes[0]);

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];
        int **A = allocateMatrix(n);
        int **B = allocateMatrix(n);
        int **C = allocateMatrix(n);

        generateRandomMatrix(A, n);
        generateRandomMatrix(B, n);

        printf("\nMatrix Size: %d x %d\n", n, n);

        clock_t start, end;

        start = clock();
        multiplyIterative(A, B, C, n);
        end = clock();
        printf("Iterative Time: %.6f sec\n", getTime(start, end));

        start = clock();
        multiplyRecursive(A, B, C, n);
        end = clock();
        printf("Recursive Time: %.6f sec\n", getTime(start, end));

        start = clock();
        strassen(A, B, C, n);
        end = clock();
        printf("Strassen Time: %.6f sec\n", getTime(start, end));

        freeMatrix(A, n);
        freeMatrix(B, n);
        freeMatrix(C, n);
    }
    return 0;
}
