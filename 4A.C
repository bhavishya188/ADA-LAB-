#include <stdio.h>
#include <time.h>

// Function to print Fibonacci series
void printFibonacci(int n) {
    int t1 = 0, t2 = 1;
    int nextTerm;

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    // Measure execution time
    clock_t start = clock();

    printFibonacci(terms);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to generate Fibonacci series: %f seconds\n", time_taken);

    return 0;
}
