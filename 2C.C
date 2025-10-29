#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort implementation
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Optional: print array contents
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int sizes[] = {10, 1000, 10000, 100000, 1000000};
    srand((unsigned int)time(NULL));

    for (int s = 0; s < 5; s++) {
        int n = sizes[s];
        int arr = (int)malloc(n * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed for size %d\n", n);
            continue;
        }

        for (int i = 0; i < n; i++)
            arr[i] = rand() % 10000;

        printf("Test case %d: Size = %d\n", s + 1, n);
        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n\n", time_taken);

        free(arr);
    }

    return 0;
}
