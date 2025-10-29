#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selection Sort implementation
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Optional: print array contents
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int sizes[] = {1000, 10000, 100000, 1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand((unsigned)time(NULL));

    for (int t = 0; t < num_sizes; t++) {
        int n = sizes[t];
        int* arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed for size %d\n", n);
            continue;
        }

        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;

        printf("Test case %d: Size = %d\n", t + 1, n);
        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n\n", time_taken);

        free(arr);
    }

    return 0;
}
