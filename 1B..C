#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary Search function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; // key found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // key not found
}

int main() {
    int n, key;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Generate sorted array [0, 1, 2, ..., n-1]
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    // Pick a random key to search
    srand(time(0));
    key = rand() % n;

    // Measure time for Binary Search
    start = clock();
    int result = binarySearch(arr, n, key);
    end = clock();

    // Calculate time taken
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Display results
    if (result != -1)
        printf("Key searched: %d, Found at index: %d\n", key, result);
    else
        printf("Key searched: %d, Not found\n", key);

    printf("Time taken for n = %d: %f seconds\n", n, time_taken);

    // Free allocated memory
    free(arr);
    return 0;
}
