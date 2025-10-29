#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Optional: print array contents
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int sizes[] = {1000, 5000, 10000, 100000, 200000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand((unsigned int)time(NULL));

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int arr = (int)malloc(n * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed for size %d\n", n);
            continue;
        }

        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }

        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n\n", time_taken);

        free(arr);
    }

    return 0;
}
