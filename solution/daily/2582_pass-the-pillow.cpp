//
// Created by Anti on 2023/9/26.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
public:
    int passThePillow(int n, int time) {
        int rest = time%(n*2-2);
        return rest<n?(rest+1):2*n-rest-1;
    }
};

TEST(test2582,SAMPLE1) {
    Solution s;
    // rest     0 1 2 3 4 5
    // num      1 2 3 4 3 2 (n-1 + n-2)
    // num-2    1 2 3 4 3 2
    EXPECT_EQ(s.passThePillow(4,5),2);
}

TEST(test2582,SAMPLE2) {
    Solution s;
    // 1 2 3 2
    EXPECT_EQ(s.passThePillow(3,2),3);
}
