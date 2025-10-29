#include <stdio.h>
#include <time.h>

// Function to compute nth Fibonacci using Bottom-Up DP (Tabulation)
int nthFibonacci(int n) {
    if (n <= 1)
        return n;

    // Create an array to store Fibonacci numbers
    int dp[n + 1];

    // Initialize the first two Fibonacci numbers
    dp[0] = 0;
    dp[1] = 1;

    // Fill the dp array iteratively
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    clock_t start = clock();

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
        printf("%d, ", nthFibonacci(i));

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to compute Fibonacci series with tabulation: %f seconds\n", time_taken);

    return 0;
}
