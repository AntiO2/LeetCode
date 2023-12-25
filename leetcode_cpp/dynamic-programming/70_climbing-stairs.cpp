/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/climbing-stairs
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int climbStairs(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
TEST(test70, SAMPLE1) {
  Solution sol;
}

TEST(test70, SAMPLE2) {
  Solution sol;
}