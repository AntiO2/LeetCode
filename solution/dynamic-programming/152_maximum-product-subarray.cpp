/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/maximum-product-subarray
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    std::vector positive(nums.size(), 0);
    std::vector negative(nums.size(), 0);
    positive[0] = nums[0];
    negative[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      positive[i] = std::max(
          std::max(negative[i - 1] * nums[i], positive[i - 1] * nums[i]),
          nums[i]);
      negative[i] = std::min(
          std::min(positive[i - 1] * nums[i], negative[i - 1] * nums[i]),
          nums[i]);
    }
    auto ans = positive[0];
    for (int i = 0; i < nums.size(); i++) {
      ans = std::max(ans, positive[i]);
    }
    return ans;
  }
};  // maximum-product-subarray

TEST(test152, SAMPLE1) {
  Solution sol;
  std::vector nums{-2, 3, -4};
  EXPECT_EQ(sol.maxProduct(nums), 24);
}

TEST(test152, SAMPLE2) {
  Solution sol;
}