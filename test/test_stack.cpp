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

    stack.push(10);
    stack.push(11);
    stack.push(12);
    stack.push(13);
    stack.push(14);

    CHECK(stack.pop().value() == 14);
    CHECK(stack.pop().value() == 13);
    CHECK(stack.pop().value() == 12);
    CHECK(stack.pop().value() == 11);
    CHECK(stack.pop().value() == 10);

    CHECK(stack.pop().has_value() == false);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.inverse();

    CHECK(stack.pop().value() == 1);
    CHECK(stack.pop().value() == 2);
    CHECK(stack.pop().value() == 3);
    CHECK(stack.pop().value() == 4);
    CHECK(stack.pop().value() == 5);
}
