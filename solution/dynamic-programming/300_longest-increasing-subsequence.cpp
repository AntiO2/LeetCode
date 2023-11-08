/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/longest-increasing-subsequence
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    if (!n) {
      return 0;
    }
    std::vector dp(n + 1, 1);
    dp[1] = nums[0];
    int len = 1;  // 当前的最大长度。
    for (int i = 0; i < n; ++i) {
      if (nums[i] > dp[len]) {
        dp[++len] = nums[i];
      } else {
        auto iter = std::lower_bound(dp.begin() + 1, dp.begin() + len + 1,
                                     nums[i]);  // 找到第一个可以更新的len
        dp[std::distance(dp.begin(), iter)] = nums[i];
      }
    }
    return len;
  }
  int lengthOfLIS2(std::vector<int>& nums) {
    std::vector dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
    }
    auto ans = 1;
    for (auto d : dp) {
      ans = std::max(ans, d);
    }
    return ans;
  }
};  // longest-increasing-subsequence

TEST(test300, SAMPLE1) {
  Solution sol;
  std::vector nums{10, 9, 2, 5, 3, 7, 101, 18};
  EXPECT_EQ(sol.lengthOfLIS(nums), 4);
}

TEST(test300, SAMPLE2) {
  Solution sol;
}