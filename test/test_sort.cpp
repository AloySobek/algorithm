#include <cstdlib>
#include <doctest.h>
#include <iostream>
#include <vector>

#include "sort.hpp"

TEST_CASE("Bubble sort") {
    std::vector<int> data{5, 1, 4, 7, 2, 3, 6};

    sort::bubble(data.begin(), data.end(),
                 std::function<bool(std::vector<int>::iterator, std::vector<int>::iterator)>(
                     [](std::vector<int>::iterator a, std::vector<int>::iterator b) -> bool {
                         return *a < *b;
                     }));

    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}
