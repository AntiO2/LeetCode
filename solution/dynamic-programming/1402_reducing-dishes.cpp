/**
 * @author Anti
 * @date 2023/10/22
 * @see https://leetcode.cn/problems/reducing-dishes
 */

#include <algorithm>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int maxSatisfaction(std::vector<int>& satisfaction) {
    int n = satisfaction.size();
    int dp[n + 1][n + 1];
    int ans = 0;
    dp[0][0] = 0;
    std::ranges::sort(satisfaction);
    for (int i = 1; i <= n; ++i) {
      // 只考虑前i道菜
      dp[i][0] = 0;
      for (int j = 1; j <= i; ++j) {
        // 使用前i道菜，填充前j个位置。
        // 在前j道菜中，选择第i道菜放在第j个位置。
        dp[i][j] = dp[i - 1][j - 1] + j * satisfaction[i - 1];  // 选择第i道菜
        if (j < i && dp[i - 1][j] > dp[i][j]) {
          dp[i][j] = dp[i - 1][j];  // 不选用第i道菜。
        }
      }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      res = std::max(res, dp[n][i]);
    }
    return res;
  }
};
TEST(test1402, SAMPLE1) {
  Solution sol;
  std::vector s{-1, -8, 0, 5, -9};
  int ans = 14;
  EXPECT_EQ(sol.maxSatisfaction(s), ans);
}

TEST(test1402, SAMPLE2) {
  Solution sol;
  std::vector s{4, 3, 2};
  int ans = 20;
  EXPECT_EQ(sol.maxSatisfaction(s), ans);
}