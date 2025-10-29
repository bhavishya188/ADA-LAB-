#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // Element found at index i
    }
    return -1;  // Element not found
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Generate random array elements
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    // Choose the last element as the key (worst case scenario)
    key = arr[n - 1];

    // Start measuring time
    clock_t start = clock();

    // Perform Linear Search 1000 times to average the time
    for (int i = 0; i < 1000; i++) {
        int result = linearSearch(arr, n, key);
    }

    // End measuring time
    clock_t end = clock();

    // Calculate average time per run
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    // Display results
    printf("Element searched: %d\n", key);
    printf("Time taken for n = %d is %f seconds (averaged over 1000 runs)\n", n, time_taken);

    // Free allocated memory
    free(arr);

    return 0;
}
