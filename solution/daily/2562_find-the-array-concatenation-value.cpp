//
// Created by Anti on 2023/10/12.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"

class Solution {
public:
    long long findTheArrayConcVal(std::vector<int> &nums) {
        auto ans = 0ll;
        size_t l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (l == r) {
                ans += nums[l];
                break;
            }
            int scale = 1;
            while (scale <= nums[r]) {
                scale *= 10;
            }
            ans = ans + scale * nums[l] + nums[r];
            l++;
            r--;
        }
        return ans;
    }
};

TEST(test2562, SAMPLE1) {
    Solution s;
    std::vector nums = {7, 52, 2, 4};
    EXPECT_EQ(s.findTheArrayConcVal(nums), 596);
}

TEST(test2562, SAMPLE2) {
    Solution s;
    std::vector nums = {5, 14, 13, 8, 12};
    EXPECT_EQ(s.findTheArrayConcVal(nums), 673);
}