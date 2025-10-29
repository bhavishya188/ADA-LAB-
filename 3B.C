#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Utility functions
void fillMatrix(int n, int **mat) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
mat[i][j] = rand() % 10;
}
void add(int n, int **A, int **B, int **result) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
result[i][j] = A[i][j] + B[i][j];
}
void subtract(int n, int **A, int **B, int **result) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
result[i][j] = A[i][j] - B[i][j];
}
void multiplyRecursive(int n, int **A, int **B, int **C) {
if (n == 1) {
C[0][0] = A[0][0] * B[0][0];
return;
}
int newSize = n / 2;
// Allocate submatrices
int **A11 = malloc(newSize * sizeof(int *));
int **A12 = malloc(newSize * sizeof(int *));
int **A21 = malloc(newSize * sizeof(int *));
int **A22 = malloc(newSize * sizeof(int *));
int **B11 = malloc(newSize * sizeof(int *));
int **B12 = malloc(newSize * sizeof(int *));
int **B21 = malloc(newSize * sizeof(int *));
int **B22 = malloc(newSize * sizeof(int *));
int **C11 = malloc(newSize * sizeof(int *));
int **C12 = malloc(newSize * sizeof(int *));
int **C21 = malloc(newSize * sizeof(int *));
26 | P a g e
int **C22 = malloc(newSize * sizeof(int *));
int **M1 = malloc(newSize * sizeof(int *));
int **M2 = malloc(newSize * sizeof(int *));
int **M3 = malloc(newSize * sizeof(int *));
int **M4 = malloc(newSize * sizeof(int *));
int **M5 = malloc(newSize * sizeof(int *));
int **M6 = malloc(newSize * sizeof(int *));
int **M7 = malloc(newSize * sizeof(int *));
int **M8 = malloc(newSize * sizeof(int *));
for (int i = 0; i < newSize; i++) {
A11[i] = malloc(newSize * sizeof(int));
A12[i] = malloc(newSize * sizeof(int));
A21[i] = malloc(newSize * sizeof(int));
A22[i] = malloc(newSize * sizeof(int));
B11[i] = malloc(newSize * sizeof(int));
B12[i] = malloc(newSize * sizeof(int));
B21[i] = malloc(newSize * sizeof(int));
B22[i] = malloc(newSize * sizeof(int));
C11[i] = malloc(newSize * sizeof(int));
C12[i] = malloc(newSize * sizeof(int));
C21[i] = malloc(newSize * sizeof(int));
C22[i] = malloc(newSize * sizeof(int));
M1[i] = malloc(newSize * sizeof(int));
M2[i] = malloc(newSize * sizeof(int));
M3[i] = malloc(newSize * sizeof(int));
M4[i] = malloc(newSize * sizeof(int));
M5[i] = malloc(newSize * sizeof(int));
M6[i] = malloc(newSize * sizeof(int));
M7[i] = malloc(newSize * sizeof(int));
M8[i] = malloc(newSize * sizeof(int));
}
// Divide matrices
for (int i = 0; i < newSize; i++)
for (int j = 0; j < newSize; j++) {
A11[i][j] = A[i][j];
A12[i][j] = A[i][j + newSize];
A21[i][j] = A[i + newSize][j];
A22[i][j] = A[i + newSize][j + newSize];
B11[i][j] = B[i][j];
B12[i][j] = B[i][j + newSize];
B21[i][j] = B[i + newSize][j];
B22[i][j] = B[i + newSize][j + newSize];
}
// Recursive multiplications
multiplyRecursive(newSize, A11, B11, M1);
multiplyRecursive(newSize, A12, B21, M2);
multiplyRecursive(newSize, A11, B12, M3);
multiplyRecursive(newSize, A12, B22, M4);
multiplyRecursive(newSize, A21, B11, M5);
multiplyRecursive(newSize, A22, B21, M6);
multiplyRecursive(newSize, A21, B12, M7);
multiplyRecursive(newSize, A22, B22, M8);
// Add results
add(newSize, M1, M2, C11);
add(newSize, M3, M4, C12);
add(newSize, M5, M6, C21);
add(newSize, M7, M8, C22);
// Combine results into C
for (int i = 0; i < newSize; i++)
for (int j = 0; j < newSize; j++) {
C[i][j] = C11[i][j];
C[i][j + newSize] = C12[i][j];
C[i + newSize][j] = C21[i][j];
C[i + newSize][j + newSize] = C22[i][j];
}
// Free memory
for (int i = 0; i < newSize; i++) {
free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]);
free(B11[i]); free(B12[i]); free(B21[i]); free(B22[i]);
free(C11[i]); free(C12[i]); free(C21[i]); free(C22[i]);
free(M1[i]); free(M2[i]); free(M3[i]); free(M4[i]);
free(M5[i]); free(M6[i]); free(M7[i]); free(M8[i]);
}
free(A11); free(A12); free(A21); free(A22);
free(B11); free(B12); free(B21); free(B22);
free(C11); free(C12); free(C21); free(C22);
free(M1); free(M2); free(M3); free(M4);
free(M5); free(M6); free(M7); free(M8);
}
int main() {
srand(time(NULL));
FILE *file = fopen("recursive_times.csv", "w");
fprintf(file, "Size,Time\n");
int sizes[] = {8, 16, 32, 64,128,256,512,1024};
int numSizes = sizeof(sizes) / sizeof(sizes[0]);
printf("Recursive Matrix Multiplication\n");
printf("Size\tTime (seconds)\n");
for (int s = 0; s < numSizes; s++) {
int n = sizes[s];
// Allocate matrices
28 | P a g e
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
multiplyRecursive(n, A, B, C);
clock_t end = clock();
double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
fprintf(file, "%d,%f\n", n, timeTaken);
printf("%d\t%f\n", n, timeTaken);
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
return 0;
}
