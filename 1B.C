Procedure Strassen_Multiply_4x4(A, B, C)
    Divide A into 4 sub-matrices (2×2):
        A11, A12, A21, A22
    Divide B into 4 sub-matrices (2×2):
        B11, B12, B21, B22
    For each 2×2 block multiplication:
        Call Strassen_2x2(Aij, Bkl) to compute intermediate results
    Procedure Strassen_2x2(A, B, C)
        p1 = (A11 + A22) * (B11 + B22)
        p2 = (A21 + A22) * B11
        p3 = A11 * (B12 - B22)
        p4 = A22 * (B21 - B11)
        p5 = (A11 + A12) * B22
        p6 = (A21 - A11) * (B11 + B12)
        p7 = (A12 - A22) * (B21 + B22)
        C11 = p1 + p4 - p5 + p7
        C12 = p3 + p5
        C21 = p2 + p4
        C22 = p1 - p2 + p3 + p6
    // Combine 2×2 results back into 4×4 matrix C
    Assemble:
        C11 → top-left of C
        C12 → top-right of C
        C21 → bottom-left of C
        C22 → bottom-right of C



#include <stdio.h>

#define N 4

// Print matrix
void printMat(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6d", M[i][j]);
        }
        printf("\n");
    }
}

// Strassen on 2x2 matrices (helper)
void strassen2(int A[2][2], int B[2][2], int C[2][2]) {
    int p1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int p2 = (A[1][0] + A[1][1]) * B[0][0];
    int p3 = A[0][0] * (B[0][1] - B[1][1]);
    int p4 = A[1][1] * (B[1][0] - B[0][0]);
    int p5 = (A[0][0] + A[0][1]) * B[1][1];
    int p6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int p7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = p1 + p4 - p5 + p7;
    C[0][1] = p3 + p5;
    C[1][0] = p2 + p4;
    C[1][1] = p1 - p2 + p3 + p6;
}

// Strassen on 4x4 by splitting into 2x2 blocks
void strassen4(int A[N][N], int B[N][N], int C[N][N]) {
    int a11[2][2], a12[2][2], a21[2][2], a22[2][2];
    int b11[2][2], b12[2][2], b21[2][2], b22[2][2];
    int c11[2][2], c12[2][2], c21[2][2], c22[2][2];
    
    // Fill sub-blocks
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j+2];
            a21[i][j] = A[i+2][j];
            a22[i][j] = A[i+2][j+2];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j+2];
            b21[i][j] = B[i+2][j];
            b22[i][j] = B[i+2][j+2];
        }
    }

    // Apply Strassen on each 2x2 block combo
    strassen2(a11, b11, c11);
    int temp[2][2];

    strassen2(a11, b12, temp); 
    for (int i=0;i<2;i++) for(int j=0;j<2;j++) c12[i][j]=temp[i][j];
    strassen2(a12, b22, temp); 
    for (int i=0;i<2;i++) for(int j=0;j<2;j++) c12[i][j]+=temp[i][j];

    strassen2(a21, b11, temp); 
    for (int i=0;i<2;i++) for(int j=0;j<2;j++) c21[i][j]=temp[i][j];
    strassen2(a22, b21, temp); 
    for (int i=0;i<2;i++) for(int j=0;j<2;j++) c21[i][j]+=temp[i][j];

    strassen2(a21, b12, temp); 
    for (int i=0;i<2;i++) for(int j=0;j<2;j++) c22[i][j]=temp[i][j];
    strassen2(a22, b22, temp); 
    for (int i=0;i<2;i++) for(int j=0;j<2;j++) c22[i][j]+=temp[i][j];

    // Assemble C (for demo, we just put block results in place)
    for (int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            C[i][j]   = c11[i][j];
            C[i][j+2] = c12[i][j];
            C[i+2][j] = c21[i][j];
            C[i+2][j+2] = c22[i][j];
        }
    }
}

int main() {
    int A[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    int B[N][N] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1},
    };

    int C[N][N] = {0};

    printf("Matrix A:\n"); 
    printMat(A);
    printf("\nMatrix B:\n"); 
    printMat(B);

    strassen4(A, B, C);

    printf("\nResult with Strassen 4x4:\n"); 
    printMat(C);

    return 0;
}
