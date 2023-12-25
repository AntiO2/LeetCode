/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/pascals-triangle
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans{std::vector<int>{1}};
    for (int i = 1; i < numRows; i++) {
      std::vector<int> row(1, 1);
      for (int j = 1; j < i; j++) {
        row.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
      }
      row.push_back(1);
      ans.push_back(row);
    }
    return ans;
  }
};

TEST(test118, SAMPLE1) {
  Solution sol;
  sol.generate(5);
}

TEST(test118, SAMPLE2) {
  Solution sol;
}