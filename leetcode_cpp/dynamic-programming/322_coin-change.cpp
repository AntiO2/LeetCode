/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/coin-change
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      int min = INT_MAX;
      for (auto coin : coins) {
        if (i >= coin && dp[i - coin] != -1) {
          min = std::min(min, dp[i - coin] + 1);
        }
      }
      dp[i] = min == INT_MAX ? -1 : min;
    }
    return dp[amount];
  }
};  // coin-change

TEST(test322, SAMPLE1) {
  Solution sol;
  std::vector coins{1, 2, 5};
  EXPECT_EQ(sol.coinChange(coins, 11), 3);
}

TEST(test322, SAMPLE2) {
  Solution sol;
  std::vector coins{2};
  EXPECT_EQ(sol.coinChange(coins, 3), -1);
}