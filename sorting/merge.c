#include <stdio.h>
#include <stdlib.h>

// Grasping the concept first, tidy up later
//

void print_array(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void merge_sort(int *array, int start, int end) {
    if (start >= end) {
        return;
    }

    int med = (end + start) / 2;

    merge_sort(array, start, med);
    merge_sort(array, med + 1, end);

    int *left = (int *)malloc(sizeof(int) * (med + 1));
    int *right = (int *)malloc(sizeof(int) * (end - med));

    for (int i = 0; i < med + 1; ++i) {
        left[i] = array[i];
    }

    for (int j = 0; j < end - med; ++j) {
        right[j] = array[(end - med) + j];
    }

    print_array(left, med + 1);
    print_array(left, end - med);
    printf("---\n");

    int i = 0, j = 0;

    for (; i < med + 1 && j < end - med;) {
        if (left[i] > right[j]) {
            array[start++] = right[j++];
        } else {
            array[start++] = left[i++];
        }
    }

    for (; i < med + 1; ++i) {
        array[start++] = left[i];
    }

    for (; j < end - med; ++j) {
        array[start++] = left[j];
    }

    free(left);
    free(right);
}

int main(int argc, char **argv) {
    int *array = (int *)malloc(sizeof(int) * (argc - 1));

    for (int i = 1; i < argc; ++i) {
        array[i - 1] = atoi(argv[i]);
    }

    merge_sort(array, 0, argc - 2);

    printf("Sorted array:\t"), print_array(array, argc - 1);

    free(array);

    return 0;
}
