/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/minimum-path-sum
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    auto m = grid.size();
    auto n = grid[0].size();
    std::vector<std::vector<int>> path(m, std::vector<int>(n, INT_MAX));
    path[0][0] = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i > 0) {
          path[i][j] = path[i - 1][j];
        }
        if (j > 0) {
          path[i][j] = std::min(path[i][j - 1], path[i][j]);
        }
        path[i][j] += grid[i][j];
      }
    }
    return path[m - 1][n - 1];
  }
};

TEST(test64, SAMPLE1) {
  Solution sol;
}

TEST(test64, SAMPLE2) {
  Solution sol;
}