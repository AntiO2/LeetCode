/**
 * @author Anti
 * @date 2023/10/20
 * @see https://leetcode.cn/problems/set-matrix-zeroes
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    bool first_row_0 = false;
    for (int i = 0; i < col; ++i) {
      if (!matrix[0][i]) {
        first_row_0 = true;
      }
      for (int j = 1; j < row; ++j) {
        if (!matrix[j][i]) {
          matrix[j][0] = 0;
          matrix[0][i] = 0;
        }
      }
    }
    for (int j = col - 1; j >= 0; --j) {
      for (int i = 1; i < row; ++i) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0) {
          matrix[i][j] = 0;
        }
      }
      if (first_row_0) {
        matrix[0][j] = 0;
      }
    }
  }
};

TEST(test73, SAMPLE1) {
  Solution sol;
  std::vector<std::vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  std::vector<std::vector<int>> ans{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  sol.setZeroes(matrix);
  EXPECT_EQ(matrix, ans);
}

TEST(test73, SAMPLE2) {
  Solution sol;
  std::vector<std::vector<int>> matrix{
      {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  std::vector<std::vector<int>> ans{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
  sol.setZeroes(matrix);
  EXPECT_EQ(matrix, ans);
}