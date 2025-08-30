Divide and Conqueror Method Pseudocode:
Procedure MultiplyDC(A, B, C, size, aR, aC, bR, bC, cR, cC):
    if size = 1 then
        C[cR][cC] ← C[cR][cC] + A[aR][aC] × B[bR][bC]
        return
    end if
    half ← size / 2
    // Compute submatrices of C using recursive calls
    // C11 = A11×B11 + A12×B21
    MultiplyDC(A, B, C, half, aR, aC, bR, bC, cR, cC)
    MultiplyDC(A, B, C, half, aR, aC+half, bR+half, bC, cR, cC)
    // C12 = A11×B12 + A12×B22
    MultiplyDC(A, B, C, half, aR, aC, bR, bC+half, cR, cC+half)
    MultiplyDC(A, B, C, half, aR, aC+half, bR+half, bC+half, cR, cC+half)
    // C21 = A21×B11 + A22×B21
    MultiplyDC(A, B, C, half, aR+half, aC, bR, bC, cR+half, cC)
    MultiplyDC(A, B, C, half, aR+half, aC+half, bR+half, bC, cR+half, cC)
    // C22 = A21×B12 + A22×B22
    MultiplyDC(A, B, C, half, aR+half, aC, bR, bC+half, cR+half, cC+half)
    MultiplyDC(A, B, C, half, aR+half, aC+half, bR+half, bC+half, cR+half, cC+half)


#include <stdio.h>
#define N 4

// Recursive function for divide-and-conquer matrix multiplication
void multiplyDC(int A[N][N], int B[N][N], int C[N][N], int size,
                int aR, int aC, int bR, int bC, int cR, int cC) {
    if (size == 1) {
        C[cR][cC] += A[aR][aC] * B[bR][bC];
        return;
    }
    int half = size / 2;

    // C11 = A11*B11 + A12*B21
    multiplyDC(A, B, C, half, aR, aC, bR, bC, cR, cC);
    multiplyDC(A, B, C, half, aR, aC + half, bR + half, bC, cR, cC);

    // C12 = A11*B12 + A12*B22
    multiplyDC(A, B, C, half, aR, aC, bR, bC + half, cR, cC + half);
    multiplyDC(A, B, C, half, aR, aC + half, bR + half, bC + half, cR, cC + half);

    // C21 = A21*B11 + A22*B21
    multiplyDC(A, B, C, half, aR + half, aC, bR, bC, cR + half, cC);
    multiplyDC(A, B, C, half, aR + half, aC + half, bR + half, bC, cR + half, cC);

    // C22 = A21*B12 + A22*B22
    multiplyDC(A, B, C, half, aR + half, aC, bR, bC + half, cR + half, cC + half);
    multiplyDC(A, B, C, half, aR + half, aC + half, bR + half, bC + half, cR + half, cC + half);
}

// Print matrix
void printMatrix(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6d ", M[i][j]);
        }
        printf("\n");
    }
}

// Simple iterative multiply for check
void multiplySimple(int A[N][N], int B[N][N], int R[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            R[i][j] = 0;
            for (int k = 0; k < N; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[N][N] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    int C[N][N] = {0};

    printf("Matrix A:\n");
    printMatrix(A);

    printf("\nMatrix B:\n");
    printMatrix(B);

    multiplyDC(A, B, C, N, 0, 0, 0, 0, 0, 0);
    printf("\nResult using Divide-and-Conquer:\n");
    printMatrix(C);

    int check[N][N];
    multiplySimple(A, B, check);
    printf("\nResult using Simple Multiply (check):\n");
    printMatrix(check);

    return 0;
}
OUTPUT:

