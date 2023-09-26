//
// Created by Anti
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution{}; // fill in it

TEST(test0,SAMPLE1) {
    Solution s;
}

TEST(test0,SAMPLE2) {
    Solution s;
}

//TEST(test0,SAMPLE3) {
//    std::list<int > list = {1,3,5,7,9};
//    list.insert(list.end(),2);
//    EXPECT_EQ(list.size(),6);
//}


TEST(test0,SAMPLE4) {
    auto a = 9;
    printf("%d %d\n", a = a+4,a*4);
}