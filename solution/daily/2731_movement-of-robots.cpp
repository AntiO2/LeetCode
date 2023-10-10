//
// Created by Anti on 2023/10/10.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"

class Solution {
public:
    int sumDistance(std::vector<int> &nums, std::string s, int d) {
        constexpr int mod = 1e9 + 7;
        long long ans = 0;
        int l = int(nums.size());
        std::vector<long long> final(l);
        for (int i = 0; i < l; i++) {
            if (s[i] == 'R') {
                final[i] = nums[i] + d;
            } else {
                final[i] = nums[i] - d;
            }
        }
        std::sort(final.begin(), final.end());
        long long prev = 0;
        for (int i = 0; i < l; ++i) {
            ans = (ans + i * final[i] - prev) % mod;
            prev += final[i];
        }
        return int(ans);
    }
};

TEST(test2731, SAMPLE1) {
    Solution s;
    std::vector<int> nums{-2, 0, 2};
    std::string c = "RLL";
    int d = 3;
    EXPECT_EQ(s.sumDistance(nums, c, d), 8);
    LOG_INFO("SAMPLE1 PASS");
}

TEST(test2731, SAMPLE2) {
    Solution s;

    std::vector<int> nums{1, 0};
    std::string c = "RL";
    int d = 2;
    EXPECT_EQ(s.sumDistance(nums, c, d), 5);
    LOG_INFO("SAMPLE2 PASS");
}