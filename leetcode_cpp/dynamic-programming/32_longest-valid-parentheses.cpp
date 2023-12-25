/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/longest-valid-parentheses
 */

#include <stack>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int longestValidParentheses(std::string s) {
    if (s.empty()) {
      return 0;
    }
    std::vector dp(s.length(), 0);
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ')') {
        if (i >= 1 && s[i - 1] == '(') {
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        } else if (i >= 1 && i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
          // 连续两个右扩号
          dp[i] =
              dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
      }
    }
    return *std::max_element(dp.begin(), dp.end());
  }
};

TEST(test32, SAMPLE1) {
  Solution sol;
  std::string s = "(()";
  EXPECT_EQ(sol.longestValidParentheses(s), 2);
}

TEST(test32, SAMPLE2) {
  Solution sol;
  std::string s = ")()())";
  EXPECT_EQ(sol.longestValidParentheses(s), 4);
}