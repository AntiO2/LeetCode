/**
 * @author Anti
 * @date 2023/10/23
 * @see https://leetcode.cn/problems/rotate-image
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    int n = int(matrix.size());
    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < (n + 1) / 2; ++j) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = tmp;
      }
    }
  }
};

TEST(test48, SAMPLE1) {
  Solution sol;
}

TEST(test48, SAMPLE2) {
  Solution sol;
}