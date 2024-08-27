#include <functional>

namespace sort {
template <class I> inline void bubble(I begin, I end, std::function<bool(I a, I b)> predicate) {
    I b = begin;

    for (int i = 1, s = 1; b != end && s; ++b, ++i) {
        s = 0;

        for (I bb = begin; bb != end - i; ++bb) {
            if (predicate(bb, bb + 1)) {
                std::iter_swap(bb, bb + 1);

                s = 1;
            }
        }
    }
}

// Quicksort is not that hard when we break down the main concepts in it. First and the most
// important is the pivot. We can choose it randomly or intelligently according to some heuristic.
// Then according to the algorithm all elements less then pivot should precede it and everything
// else should succeed the pivot. That is, [x1, x2, x3 ... ] < pivot < [x4, x5, x6 ... ]. Doing so
// we divide our initial array into two subarrays which we can sort the same way, i.e divide and
// conquer approach. When we get to the base case we have sorted array and all that's left to do is
// combine the parts in order to restore the whole, sorted array. The most complex to understand and
// implement part is the partition process.
inline void quick(int *arr, int start, int end) {
    int index = start;
    int pivot = arr[index];

    for (int i = index + 1; i < end; ++i) {
        if (pivot > arr[i]) {
            int tmp = arr[i];

            arr[i] = pivot;
        }
    }
}

} // namespace sort
