cmake_minimum_required(VERSION 3.20)

project(
  algorithm
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(DOWNLOAD
     https://raw.githubusercontent.com/doctest/doctest/v2.4.11/doctest/doctest.h
     ${CMAKE_SOURCE_DIR}/doctest.h)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(main main.cpp)

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(main PRIVATE ${PROJECT_NAME})
