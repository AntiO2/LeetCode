//
// Created by Anti on 2023/10/16.
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<int> singleNumber(std::vector<int>& nums) {
    int tmp = 0;
    for (const auto& num : nums) {
      tmp ^= num;
    }
    int left = (tmp == INT32_MIN ? tmp : tmp & (-tmp));
    int ans1 = 0;
    int ans2 = 0;
    for (const auto& num : nums) {
      if (num & left) {
        ans1 ^= num;
      } else {
        ans2 ^= num;
      }
    }
    return {ans1, ans2};
  }
};
TEST(test260, SAMPLE1) {
  Solution s;
  std::vector nums{1, 2, 1, 3, 2, 5};
  std::vector ans{3, 5};
  EXPECT_EQ(s.singleNumber(nums), ans);
}

TEST(test260, SAMPLE2) {
  Solution s;
  std::vector nums{-1, 0};
  std::vector ans{-1, 0};
  EXPECT_EQ(s.singleNumber(nums), ans);
}
TEST(test260, SAMPLE3) {
  Solution s;
  std::vector nums{0, 1};
  std::vector ans{0, 1};
  EXPECT_EQ(s.singleNumber(nums), ans);
}