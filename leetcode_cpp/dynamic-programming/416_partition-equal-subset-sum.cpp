/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/partition-equal-subset-sum
 */

#include <numeric>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  bool canPartition(std::vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return false;
    }
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int maxNum = *max_element(nums.begin(), nums.end());
    if (sum & 1) {
      return false;
    }
    int target = sum / 2;
    if (maxNum > target) {
      return false;
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(target + 1, 0));
    for (int i = 0; i < n; i++) {
      dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++) {
      int num = nums[i];
      for (int j = 1; j <= target; j++) {
        if (j >= num) {
          dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n - 1][target];
  }
};

TEST(test416, SAMPLE1) {
  Solution sol;
}

TEST(test416, SAMPLE2) {
  Solution sol;
}