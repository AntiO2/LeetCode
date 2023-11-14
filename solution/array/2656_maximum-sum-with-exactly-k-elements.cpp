/**
 * @author Anti
 * @date 2023/11/15
 * @see https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int maximizeSum(std::vector<int>& nums, int k) {
    return (((*std::max_element(nums.begin(), nums.end())) << 1) + k - 1) * k >>
           1;
  }
};  // maximum-sum-with-exactly-k-elements

TEST(test2656, SAMPLE1) {
  Solution sol;
  std::vector nums{1, 2, 3, 4, 5};
  int k = 3;
  EXPECT_EQ(sol.maximizeSum(nums, k), 18);
}

TEST(test2656, SAMPLE2) {
  Solution sol;
}