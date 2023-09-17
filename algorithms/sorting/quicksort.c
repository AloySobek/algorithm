#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j) {
    int tmp = arr[i];

    arr[i] = arr[j];
    arr[j] = tmp;
}

int lomuto_partition(int *arr, int start, int end) {
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if (arr[j] <= pivot) {
            i += 1;

            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, end);

    return (i + 1);
}

int hoare_partition(int *arr, int start, int end) {
    int pivot = arr[start];

    int i = start - 1;
    int j = end + 1;

    while (1) {
        do {
            ++i;
        } while (arr[i] < pivot);

        do {
            --j;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(arr, i, j);
    }
}

void quicksort(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }

    // int new_end = lomuto_partition (arr, start, end);
    int new_end = hoare_partition(arr, start, end);

    quicksort(arr, start, new_end);
    quicksort(arr, new_end + 1, end);
}

int main(int argc, char **argv) {
    int arr[64];

    if (argc > 64) {
        printf("Too much numbers!\n");

        return -1;
    }

    if (argc < 3) {
        printf("Provide at least 2 numbers!\n");

        return -1;
    }

    for (int i = 1; i < argc; ++i) {
        arr[i - 1] = atoi(argv[i]);
    }

    quicksort(arr, 0, argc - 2);

    for (int i = 0; i < argc - 1; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return (0);
}
