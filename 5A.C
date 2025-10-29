// fractional_greedy.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for an item
typedef struct {
    int profit, weight;
    float ratio;
} Item;

// Comparator function for qsort (descending order by ratio)
int compare(const void *a, const void *b) {
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;
    return (i2->ratio > i1->ratio) - (i2->ratio < i1->ratio);
}

// Fractional Knapsack function
float fractionalKnapsack(Item items[], int n, int capacity) {
    // Sort items by profit/weight ratio
    qsort(items, n, sizeof(Item), compare);

    float totalProfit = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += items[i].profit * ((float)capacity / items[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int sizes[] = {10, 50, 100, 200};  // Different n values to test
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp = fopen("fractional_greedy.csv", "w");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(fp, "n,time_ms\n");

    srand(time(NULL));

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int capacity = n * 50;

        // Allocate memory for items
        Item *items = malloc(n * sizeof(Item));
        if (items == NULL) {
            printf("Memory allocation failed\n");
            fclose(fp);
            return 1;
        }

        // Generate random items
        for (int j = 0; j < n; j++) {
            items[j].weight = rand() % 100 + 1;
            items[j].profit = rand() % 100 + 1;
            items[j].ratio = (float)items[j].profit / items[j].weight;
        }

        // Measure execution time
        clock_t start = clock();
        float profit = fractionalKnapsack(items, n, capacity);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printf("n = %d, Profit = %.2f, Time = %.2f ms\n", n, profit, time_taken);
        fprintf(fp, "%d,%.2f\n", n, time_taken);

        free(items);
    }

    fclose(fp);
    printf("Results saved to fractional_greedy.csv\n");

    return 0;
}
