/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/perfect-squares
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  std::vector<int> book;

 public:
  int numSquares(int n) {
    for (int i = 1; i <= 100; ++i) {
      book.emplace_back(i * i);
    }
    std::vector dp(10005, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < book.size(); j++) {
        if (book[j] > i) {
          break;
        }
        dp[i] = std::min(dp[i], dp[i - book[j]] + 1);
      }
    }
    return dp[n];
  }
};  // fill in it

TEST(test279, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.numSquares(12), 3);
}

TEST(test279, SAMPLE2) {
  Solution sol;

  EXPECT_EQ(sol.numSquares(13), 2);
}