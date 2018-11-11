//
// Created by dinamic on 11/10/18.
//

#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "my_array.h"

TEST(ArrayCreation, Empty) {
    my_array<int,0> arr;
    EXPECT_TRUE(arr.size() == 0);
}

TEST(ArrayCreation, Regular) {
    my_array<std::string, 3> arr {"ich", "heisse", "name"};
    EXPECT_TRUE(arr.size() == 3);
    EXPECT_TRUE(arr[0] == "ich");
}

TEST(ArrayIndexing, AtZero) {
    my_array<std::string, 2> arr {"a", "b"};
    EXPECT_TRUE(arr.at(0) == "a");
}

TEST(ArrayIndexing, AtOutside) {
    my_array<std::string, 2> arr {"a", "b"};
    EXPECT_THROW(arr.at(2), std::out_of_range);
}

TEST(ArrayIndexing, BracketsZero) {
    my_array<int, 2> arr {1,2};
    EXPECT_TRUE(arr[0] == 1);
}

TEST(ArrayIndexing, BracketsOutside) {
    my_array<int, 2> arr {43, 23};
    EXPECT_NO_THROW(arr[2]);
}

TEST(ArrayIndexing, FrontElement) {
    my_array<int, 3> arr {4,3,2};
    EXPECT_TRUE(arr.front() == 4);
}

TEST(ArrayIndexing, BackElement) {
    my_array<int, 4> arr {4,3,2,1};
    EXPECT_TRUE(arr.back() == 1);
}

TEST(ArrayIndexing, Data) {
    my_array<int, 4> arr {2,3,4,5};
    EXPECT_TRUE(*(arr.data()) == 2);
    EXPECT_TRUE(*(arr.data() + 1) == 3);
    EXPECT_TRUE(*(arr.data() + 2) == 4);
    EXPECT_TRUE(*(arr.data() + 3) == 5);
}

TEST(ArrayIterators, General){
    my_array<int,4> arr {1,2,3,4};
    EXPECT_EQ(*arr.begin(), *(arr.rend()-1));
    EXPECT_EQ(*(arr.end()-1), *arr.rbegin());
}

TEST(Iterators, Constant){
    my_array<int, 4> arr {1,2,3,4};
    EXPECT_EQ(*arr.cbegin(), *(arr.crend()-1));
    EXPECT_EQ(*(arr.cend()-1), *arr.crbegin());
}

TEST(ArrayCapacity, Empty) {
    my_array<int, 0> arr {};
    my_array<int, 3> arr_ne {1,2,3};
    EXPECT_TRUE(arr.empty());
    EXPECT_FALSE(arr_ne.empty());
}

TEST(ArrayCapacity, Size) {
    my_array<int, 0> arr {};
    my_array<int, 3> arr_ne {1,2,3};
    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr_ne.size(), 3);
}

TEST(ArrayOperations, Fill) {
    my_array<int, 3> arr;
    arr.fill(1);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 1);
    EXPECT_EQ(arr.size(), 3);
}

TEST(ArrayOperations, Swap) {
    my_array<int, 3> arr1 {1,2,3};
    my_array<int, 3> arr2 {4,5,6};
    arr1.swap(arr2);
    EXPECT_EQ(arr1[0], 4);
    EXPECT_EQ(arr1[1], 5);
    EXPECT_EQ(arr1[2], 6);
}

TEST(ArrayOperators, Equal) {
    my_array<int, 3> arr1 {1,2,3};
    my_array<int, 3> arr2 {4,5,6};
    my_array<int, 3> arr3 {1,2,3};
    my_array<int, 3> arr4 {1,2,3};
    my_array<int, 0> arr5 {};
    my_array<int, 0> arr6 {};
    EXPECT_FALSE(arr1 == arr2);
    EXPECT_TRUE(arr3 == arr4);
    EXPECT_TRUE(arr5 == arr6);
}


TEST(ArrayOperators, NotEqual) {
    my_array<int, 3> arr1 {1,2,3};
    my_array<int, 3> arr2 {4,5,6};
    my_array<int, 3> arr3 {1,2,3};
    my_array<int, 3> arr4 {1,2,3};
    my_array<int, 0> arr5 {};
    my_array<int, 0> arr6 {};
    EXPECT_TRUE(arr1 != arr2);
    EXPECT_FALSE(arr3 != arr4);
    EXPECT_FALSE(arr5 != arr6);
}

TEST(ArrayOperators, Less) {
    my_array<int, 3> arr1 {1,2,3};
    my_array<int, 3> arr2 {1,2,5};
    my_array<int, 3> arr3 {1,2,3};
    my_array<int, 3> arr4 {1,2,3};
    my_array<int, 0> arr5 {};
    my_array<int, 0> arr6 {};
    EXPECT_TRUE(arr1 < arr2);
    EXPECT_FALSE(arr3 < arr4);
    EXPECT_FALSE(arr5 < arr6);
}

TEST(ArrayOperators, Greater) {
    my_array<int, 3> arr1 {4,5,8};
    my_array<int, 3> arr2 {4,5,6};
    my_array<int, 3> arr3 {1,2,3};
    my_array<int, 3> arr4 {1,2,3};
    my_array<int, 0> arr5 {};
    my_array<int, 0> arr6 {};
    EXPECT_TRUE(arr1 > arr2);
    EXPECT_FALSE(arr3 > arr4);
    EXPECT_FALSE(arr5 > arr6);
}

TEST(ArrayOperators, LessEqual) {
    my_array<int, 3> arr1 {1,2,2};
    my_array<int, 3> arr2 {1,2,2};
    my_array<int, 3> arr3 {1,2,2};
    my_array<int, 3> arr4 {1,2,3};
    my_array<int, 1> arr5 {3};
    my_array<int, 1> arr6 {2};
    EXPECT_TRUE(arr1 <= arr2);
    EXPECT_TRUE(arr3 <= arr4);
    EXPECT_FALSE(arr5 <= arr6);
}

TEST(ArrayOperators, GreaterEqual) {
    my_array<int, 3> arr1 {1,2,2};
    my_array<int, 3> arr2 {1,2,2};
    my_array<int, 3> arr3 {1,2,3};
    my_array<int, 3> arr4 {1,2,4};
    my_array<int, 1> arr5 {3};
    my_array<int, 1> arr6 {2};
    EXPECT_TRUE(arr1 >= arr2);
    EXPECT_FALSE(arr3 >= arr4);
    EXPECT_TRUE(arr5 >= arr6);
}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
