//
// Created by Anti on 2023/10/18.
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    int n = int(nums.size());  // 最多为N + 1
    for (auto& num : nums) {
      if (num <= 0) {
        num = n + 1;
      }
    }
    for (auto& num : nums) {
      auto a = abs(num);
      if (a >= 1 && a <= n && nums[a - 1] > 0) {
        nums[a - 1] = -nums[a - 1];
      }
    }
    int i = 0;
    for (; i < n; ++i) {
      if (nums[i] > 0) {
        break;
      }
    }
    return i + 1;
  }
};
TEST(test41, SAMPLE1) {
  Solution sol;
  std::vector nums{1, 2, 0};
  int ans = 3;
  EXPECT_EQ(sol.firstMissingPositive(nums), ans);
}

TEST(test41, SAMPLE2) {
  Solution sol;
  std::vector nums{3, 4, -1, 1};
  int ans = 2;
  EXPECT_EQ(sol.firstMissingPositive(nums), ans);
}

TEST(test41, SAMPLE3) {
  Solution sol;
  std::vector nums{7, 8, 9, 11, 12};
  int ans = 1;
  EXPECT_EQ(sol.firstMissingPositive(nums), ans);
}