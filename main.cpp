#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>

#include "list.hpp"

TEST_CASE("testing the factorial function") {
    SinglyLinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    CHECK(list.find([](int x) -> bool { return x == 1; }).has_value());
    CHECK(list.find([](int x) -> bool { return x == 2; }).has_value());
    CHECK(list.find([](int x) -> bool { return x == 3; }).has_value());

    CHECK(list.at(0).has_value() && list.at(0).value() == 1);
    CHECK(list.at(1).has_value() && list.at(0).value() == 2);
    CHECK(list.at(2).has_value() && list.at(0).value() == 3);
}
