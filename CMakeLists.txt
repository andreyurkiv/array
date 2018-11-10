cmake_minimum_required(VERSION 2.8)

#option(test "Build all tests." OFF)

set(PROJECT_NAME my_array)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(my_array_lib my_array.h my_array.cpp)

add_executable(my_array main.cpp)

target_link_libraries(my_array my_array_lib)

add_subdirectory(lib/gtest-1.6.0)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests array_test.cpp)

target_link_libraries(runUnitTests gtest gtest_main)

target_link_libraries(runUnitTests my_array_lib)


