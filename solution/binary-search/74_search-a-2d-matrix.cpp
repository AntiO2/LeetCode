/**
 * @author Anti
 * @date 2023/11/7
 * @see https://leetcode.cn/problems/search-a-2d-matrix
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>> matrix, int target) {
    auto row = upper_bound(
        matrix.begin(), matrix.end(), target,
        [](const int b, const std::vector<int>& a) { return b < a[0]; });
    if (row == matrix.begin()) {
      return false;
    }
    --row;
    return binary_search(row->begin(), row->end(), target);
  }
};

TEST(test74, SAMPLE1) {
  Solution sol;
}

TEST(test74, SAMPLE2) {
  Solution sol;
}