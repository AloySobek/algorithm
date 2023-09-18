#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    assert(a != (void *)0 && b != (void *)0);

    int tmp = *a;

    *a = *b;
    *b = tmp;
}

void bubble_sort(int *array, int size) {
    assert(size > 2);
    assert(array != (void *)0);

    for (int i = size; i >= 2; --i) {
        for (int j = 0; j + 1 < i; ++j) {
            if (*(array + j) > *(array + j + 1)) {
                swap(array + j, array + j + 1);
            }
        }
    }
}
