#include <doctest.h>
#include <iostream>

#include "stack.hpp"

TEST_CASE("Stack") {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    CHECK(stack.pop().value() == 5);
    CHECK(stack.pop().value() == 4);
    CHECK(stack.pop().value() == 3);
    CHECK(stack.pop().value() == 2);
    CHECK(stack.pop().value() == 1);

    CHECK(stack.pop().has_value() == false);
}
