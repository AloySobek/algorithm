#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

void insertion_sort(int *array, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0 && *(array + j - 1) > *(array + j); --j) {
            swap(array + j, array + j - 1);
        }
    }
}

int main(int argc, char **argv) {
    int arr[1024];

    if (argc > 1024) {
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

    int *array = (int *)malloc(sizeof(int) * 1024);

    for (int i = 0; i < 1000; ++i) {
        for (int j = 1; j < argc - 1; ++j) {
            array[j - 1] = arr[i];
        }

        insertion_sort(array, argc - 1);
    }

    insertion_sort(arr, argc - 1);

    for (int i = 0; i < argc - 1; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return (0);
}
