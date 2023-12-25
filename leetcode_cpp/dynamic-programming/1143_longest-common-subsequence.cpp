/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/longest-common-subsequence
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    auto m = text1.size();
    auto n = text2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};  // longest-common-subsequence

TEST(test1143, SAMPLE1) {
  Solution sol;
  std::string s1 = "abcde", s2 = "ace";
  EXPECT_EQ(sol.longestCommonSubsequence(s1, s2), 3);
}

TEST(test1143, SAMPLE2) {
  Solution sol;
}