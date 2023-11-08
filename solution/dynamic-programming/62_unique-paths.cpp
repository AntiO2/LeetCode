/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/unique-paths
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> path(m, std::vector<int>(n, 0));
    path[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i > 0) {
          path[i][j] += path[i - 1][j];
        }
        if (j > 0) {
          path[i][j] += path[i][j - 1];
        }
      }
    }
    return path[m - 1][n - 1];
  }
};  // unique-paths

TEST(test62, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.uniquePaths(3, 7), 28);
}

TEST(test62, SAMPLE2) {
  Solution sol;
}