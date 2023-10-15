//
// Created by Anti on 2023/10/15.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"

class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int total = 0;
            for (int num: nums) {
                total += (num >> i) & 1;
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
TEST(test137, SAMPLE1) {
    Solution s;
    std::vector nums{2, 2, 3, 2};
    int ans = 3;
    EXPECT_EQ(s.singleNumber(nums), ans);
    // LOG_INFO("SAMPLE1 PASS");
}

TEST(test137, SAMPLE2) {
    Solution s;
    std::vector nums{0, 1, 0, 1, 0, 1, 99};
    int ans = 99;
    EXPECT_EQ(s.singleNumber(nums), ans);
    // LOG_INFO("SAMPLE2 PASS");
}