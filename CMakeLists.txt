cmake_minimum_required(VERSION 3.20)

project(
  algorithm
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(DOWNLOAD
     https://raw.githubusercontent.com/doctest/doctest/v2.4.11/doctest/doctest.h
     ${CMAKE_CURRENT_SOURCE_DIR}/doctest.h)

file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE TEST_SRC "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SRC})

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(test ${TEST_SRC})

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(test PRIVATE ${PROJECT_NAME})
