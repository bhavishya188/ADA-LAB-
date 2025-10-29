#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Recursive merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Optional: print array contents
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int t[] = {10, 100, 1000, 10000, 100000, 1000000};
    int num_tests = sizeof(t) / sizeof(t[0]);

    for (int i = 0; i < num_tests; i++) {
        int n = t[i];
        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) {
            fprintf(stderr, "Memory allocation failed for size %d\n", n);
            continue;
        }

        srand(time(NULL));
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;
        }

        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Size: %d, Time taken: %.6f seconds\n", n, time_taken);

        free(arr);
    }

    return 0;
}
