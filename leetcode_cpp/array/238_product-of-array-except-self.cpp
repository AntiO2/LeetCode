/**
 * @author Anti
 * @date 2023/10/20
 * @see https://leetcode.cn/problems/product-of-array-except-self
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> ans(nums.size());
    ans[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      ans[i] = ans[i - 1] * nums[i];  // 构造前缀积。
    }
    int right_total = 1;  // 后缀积
    for (int j = int(nums.size()) - 1; j > 0; --j) {
      ans[j] = ans[j - 1] * right_total;
      right_total *= nums[j];
    }
    ans[0] = right_total;
    return ans;
  }
};

TEST(test238, SAMPLE1) {
  Solution sol;
  std::vector nums{1, 2, 3, 4};
  std::vector ans{24, 12, 8, 6};
  EXPECT_EQ(sol.productExceptSelf(nums), ans);
}

TEST(test238, SAMPLE2) {
  Solution sol;
  std::vector nums{-1, 1, 0, -3, 3};
  std::vector ans{0, 0, 9, 0, 0};
  EXPECT_EQ(sol.productExceptSelf(nums), ans);
}