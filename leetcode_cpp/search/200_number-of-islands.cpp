/**
 * @author Anti
 * @date 2023/10/30
 * @see https://leetcode.cn/problems/number-of-islands
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  static constexpr char sea = '0';
  static constexpr char land = '1';
  void book(int m, int n, const std::vector<std::vector<char>>& grid,
            std::vector<std::vector<bool>>& color_book_) {
    if (n < 0 || m < 0 || m >= grid.size() || n >= grid[0].size()) {
      return;
    }
    if (grid[m][n] == sea) {
      return;
    }
    if (grid[m][n] == land) {
      if (!color_book_[m][n]) {
        LOG_INFO("Mark %d %d", m, n);
        color_book_[m][n] = true;
        book(m + 1, n, grid, color_book_);
        book(m - 1, n, grid, color_book_);
        book(m, n + 1, grid, color_book_);
        book(m, n - 1, grid, color_book_);
      } else {
        return;
      }
    }
  }

 public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int m = grid.size();
    if (m == 0) {
      return 0;
    }
    int ans = 0;
    int n = grid[0].size();
    std::vector<std::vector<bool>> color_book_(m, std::vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!color_book_[i][j] && grid[i][j] == land) {
          LOG_INFO("Start %d %d", i, j);
          book(i, j, grid, color_book_);
          ++ans;
        }
      }
    }
    return ans;
  }
};

TEST(test200, SAMPLE1) {
  Solution sol;
}

TEST(test200, SAMPLE2) {
  Solution sol;
  std::vector<std::vector<char>> map{
      std::vector<char>{'1', '1', '0', '0', '0'},
      std::vector<char>{'1', '1', '0', '0', '0'},
      std::vector<char>{'0', '0', '1', '0', '0'},
      std::vector<char>{'0', '0', '0', '1', '1'},
  };
  EXPECT_EQ(sol.numIslands(map), 3);
}