//
// Created by Anti on 2023/10/18.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"
#include <unordered_set>

class Solution {
public:
    int subarraySum(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> prevSum;//前缀和。
        prevSum.emplace(0, 1);               // 注意0也要放进去
        int sumNow = 0;
        int ans = 0;
        for (const auto &num: nums) {
            sumNow += num;
            auto iter = prevSum.find(sumNow - k);
            if (iter != prevSum.end()) {
                ans += iter->second;
            }
            prevSum[sumNow]++;
        }
        return ans;
    }
};

TEST(test560, SAMPLE1) {
    Solution s;
    std::vector nums = {1, 1, 1};
    int k = 2;
    int ans = 2;
    EXPECT_EQ(s.subarraySum(nums, k), ans);
    // LOG_INFO("SAMPLE1 PASS");
}

TEST(test560, SAMPLE2) {
    Solution s;
    std::vector nums = {1, 2, 3};
    int k = 3;
    int ans = 2;
    EXPECT_EQ(s.subarraySum(nums, k), ans);
    // LOG_INFO("SAMPLE2 PASS");
}