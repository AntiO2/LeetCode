/**
 * @author Anti
 * @date 2023/10/23
 * @see https://leetcode.cn/problems/spiral-matrix
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  const int dx[4]{0, 1, 0, -1};  // 右 下 左 上。
  const int dy[4]{1, 0, -1, 0};

 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    int x_now = 0;
    int y_now = 0;
    int m = matrix.size(), n = matrix.at(0).size();
    int dis[2]{n, m};
    std::vector<int> ans;
    ans.reserve(m * n);
    int direction = 0;
    int go_dis = dis[direction % 2];
    while (go_dis) {
      ans.emplace_back(matrix[x_now][y_now]);
      --go_dis;
      if (!go_dis) {
        direction = (direction + 1) % 4;
        --dis[direction % 2];
        go_dis = dis[direction % 2];
      }
      x_now += dx[direction];
      y_now += dy[direction];
    }
    return ans;
  }
};

TEST(test54, SAMPLE1) {
  Solution sol;
  std::vector<std::vector<int>> m{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector ans{1, 2, 3, 6, 9, 8, 7, 4, 5};
  EXPECT_EQ(sol.spiralOrder(m), ans);
}

TEST(test54, SAMPLE2) {
  Solution sol;
  std::vector<std::vector<int>> m{{1}};
  std::vector ans{1};
  EXPECT_EQ(sol.spiralOrder(m), ans);
}
TEST(test54, SAMPLE3) {
  Solution sol;
  std::vector<std::vector<int>> m{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector ans{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
  EXPECT_EQ(sol.spiralOrder(m), ans);
}