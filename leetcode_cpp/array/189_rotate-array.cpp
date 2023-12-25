/**
 * @author Anti
 * @date 2023/10/20
 * @see https://leetcode.cn/problems/rotate-array
 */

#include <algorithm>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  void rotate(std::vector<int>& nums, int k) {
    long long back_part = k % int(nums.size());
    std::ranges::reverse(nums);
    std::reverse(nums.begin(), nums.begin() + back_part);
    std::reverse(nums.begin() + back_part, nums.end());
  }
};
TEST(test189, SAMPLE1) {
  std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> ans{5, 6, 7, 1, 2, 3, 4};
  int k = 3;
  Solution sol;
  sol.rotate(nums, k);
  EXPECT_EQ(nums, ans);
}

TEST(test189, SAMPLE2) {
  std::vector<int> nums{-1, -100, 3, 99};
  std::vector<int> ans{3, 99, -1, -100};
  int k = 2;
  Solution sol;
  sol.rotate(nums, k);
  EXPECT_EQ(nums, ans);
}