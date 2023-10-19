#include "sort.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomuto_partition(int *array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
            if (i != j) {
                printf("Swap: %d <--> %d\n", array[i], array[j]);
                for (size_t k = 0; k < size; k++) {
                    printf("%d", array[k]);
                    if (k < size - 1) {
                        printf(", ");
                    }
                }
                printf("\n");
            }
        }
    }

    swap(&array[i + 1], &array[high]);
    if (i + 1 != high) {
        printf("Swap: %d <--> %d\n", array[i + 1], array[high]);
        for (size_t k = 0; k < size; k++) {
            printf("%d", array[k]);
            if (k < size - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
    return i + 1;
}

void quick_sort_helper(int *array, int low, int high, size_t size) {
    if (low < high) {
        int partition_idx = lomuto_partition(array, low, high, size);

        quick_sort_helper(array, low, partition_idx - 1, size);
        quick_sort_helper(array, partition_idx + 1, high, size);
    }
}

void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;  // No need to sort
    }

    quick_sort_helper(array, 0, size - 1, size);
}
