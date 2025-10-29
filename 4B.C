#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    printf("Fibonacci Series: ");

    // Start measuring time
    clock_t start = clock();

    for (int i = 0; i < terms; i++) {
        printf("%d, ", fib(i));
    }

    // End measuring time
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to generate Fibonacci series: %f seconds\n", time_taken);

    return 0;
}
