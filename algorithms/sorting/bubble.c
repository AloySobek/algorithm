#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// https://en.wikipedia.org/wiki/Bubble_sort

// The earliest description of the Bubble sort algorithm was in a 1956 paper by mathematician and
// actuary Edward Harry Friend, Sorting on electronic computer systems, published in the third
// issue of the third volume of the Journal of the Association for Computing Machinery (ACM) , as a
// "Sorting exchange algorithm". Friend described the fundamentals of the algorithm, and, although
// initially his paper went unnoticed, some years later, it was rediscovered by many computer
// scientists, including Kenneth E. Iverson who coined its current name.

void swap(int *a, int *b) {
    assert(a != (void *)0 && b != (void *)0);

    int tmp = *a;

    *a = *b;
    *b = tmp;
}

// Bubble sort is the simplest sorting algorithm out there. Worst case performance is O(n^2).
// Which means for n sized input you'll have squared number of operations. This algorithm is
// primarily used as learning tool, it performs poorly in real world scenario.
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
