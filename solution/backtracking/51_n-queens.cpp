/**
 * @author Anti
 * @date 2023/11/4
 * @see https://leetcode.cn/problems/n-queens
 */

#include <bitset>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  std::vector<int> rows_;   // 在每行的位置
  std::vector<bool> cols_;  // 指示第i列是否存在皇后
  std::vector<std::vector<std::string>> ans_;
  bool check(int i, int j, int n) {
    // 往右上找。
    for (int row = i - 1; row >= 0; --row) {
      if (j + 1 - row >= n) {
        break;
      }
      if (rows_[row] == j + i - row) {
        return false;
      }
    }
    // 往左上找
    for (int row = i - 1; row >= 0; --row) {
      if (j + row - i < 0) {
        break;
      }
      if (rows_[row] == j + row - i) {
        return false;
      }
    }
    return true;
  }
  void generate_ans(int n) {
    std::vector<std::string> new_solution;
    for (auto row : rows_) {
      std::string s(n, '.');
      s[row] = 'Q';
      new_solution.emplace_back(s);
    }
    ans_.emplace_back(new_solution);
  }
  void dfs(int step, int n) {
    if (step == n) {
      generate_ans(n);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (cols_[i]) {
        continue;
      }
      if (check(step, i, n)) {
        rows_[step] = i;
        cols_[i] = true;
        dfs(step + 1, n);
        cols_[i] = false;
      }
    }
  }

 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    cols_.assign(n, false);
    rows_.assign(n, -1);
    dfs(0, n);
    return ans_;
  }
};
TEST(test51, SAMPLE1) {
  Solution sol;
  sol.solveNQueens(4);
}

TEST(test51, SAMPLE2) {
  Solution sol;
  sol.solveNQueens(1);
}