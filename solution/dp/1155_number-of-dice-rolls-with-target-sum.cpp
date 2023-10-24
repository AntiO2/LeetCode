/**
 * @author Anti
 * @date 2023/10/24
 * @see https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  static constexpr int mod = 1e9 + 7;

 public:
  int numRollsToTarget(int n, int k, int target) {
    int dp[target + 1];  // 投i次，点数为j的方法
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = target; j >= 0; j--) {
        dp[j] = 0;
        // 当次投出后，和为j.
        for (int t = 1; t <= k && t <= j; t++) {
          // t为第i次投出的点数。
          dp[j] = (dp[j - t] + dp[j]) % mod;
        }
      }
    }
    return dp[target];
  }
};
class Solution2 {
 private:
  static constexpr int mod = 1e9 + 7;

 public:
  int numRollsToTarget(int n, int k, int target) {
    int dp[n + 1][target + 1];  // 投i次，点数为j的方法
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= target; j++) {
        // 当次投出后，和为j.
        for (int t = 1; t <= k && t <= j; t++) {
          // t为第i次投出的点数。
          dp[i][j] = (dp[i - 1][j - t] + dp[i][j]) % mod;
        }
      }
    }
    return dp[n][target];
  }
};

TEST(test1155, SAMPLE1) {
  Solution sol;
  int n = 1, k = 6, target = 3;
  int ans = 1;
  EXPECT_EQ(sol.numRollsToTarget(n, k, target), ans);
}

TEST(test1155, SAMPLE2) {
  Solution sol;
  int n = 2, k = 6, target = 7;
  int ans = 6;
  EXPECT_EQ(sol.numRollsToTarget(n, k, target), ans);
}
TEST(test1155, SAMPLE3) {
  Solution sol;
  int n = 30, k = 30, target = 500;
  int ans = 222616187;
  EXPECT_EQ(sol.numRollsToTarget(n, k, target), ans);
}