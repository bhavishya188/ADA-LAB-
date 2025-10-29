#include <stdio.h>
#include <time.h>

long long fib_array[100]; // Array to store Fibonacci numbers

// Recursive Fibonacci with Memoization
long long fib(int n) {
    if (n <= 1) {
        fib_array[n] = n; // store base case
        return n;
    }

    // Return cached result if available
    if (fib_array[n] != 0)
        return fib_array[n];

    // Compute and store the value
    fib_array[n] = fib(n - 1) + fib(n - 2);
    return fib_array[n];
}

int main() {
    int terms;

    printf("Enter the number of terms (up to 92): ");
    scanf("%d", &terms);

    // Initialize array with 0s
    for (int i = 0; i < 100; i++)
        fib_array[i] = 0;

    clock_t start = clock();

    printf("Fibonacci Series: ");
    for (int i = 0; i < terms; i++)
        printf("%lld, ", fib(i));

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to compute Fibonacci series with memoization: %f seconds\n", time_taken);

    return 0;
}
