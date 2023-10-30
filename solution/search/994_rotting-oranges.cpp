/**
 * @author Anti
 * @date 2023/10/30
 * @see https://leetcode.cn/problems/rotting-oranges
 */

#include <queue>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
// 感觉这题跟之前的一道挺像的
class Solution {
 private:
  int dx[4]{-1, 1, 0, 0};
  int dy[4]{0, 0, -1, 1};

 public:
  int orangesRotting(std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<int, int>> q1;  // 腐烂之源。
    std::queue<std::pair<int, int>> q2;  // 接下来的腐烂之源
    auto source = &q1;
    auto next = &q2;
    int m = int(grid.size());
    int n = int(grid[0].size());
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          source->emplace(i, j);
        }
      }
    }
    auto cnt = 0;
    while (true) {
      while (!source->empty()) {
        auto curr = source->front();
        source->pop();
        // LOG_INFO("Mark %d %d At\t%d", curr.first, curr.second, cnt);
        for (int i = 0; i < 4; i++) {
          auto nx = curr.first + dx[i];
          auto ny = curr.second + dy[i];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
          }
          if (grid[nx][ny] != 1) {
            continue;
          }
          grid[nx][ny] = 2;
          next->emplace(nx, ny);
        }
      }
      if (!next->empty()) {
        ++cnt;
        std::swap(source, next);
      } else {
        break;
      }
    }
    // 检查
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }
    return cnt;
  }
};

TEST(test994, SAMPLE1) {
  Solution sol;
  std::vector<std::vector<int>> oranges{std::vector<int>{2, 1, 1},
                                        std::vector<int>{1, 1, 0},
                                        std::vector<int>{0, 1, 1}};
  EXPECT_EQ(sol.orangesRotting(oranges), 4);
}

TEST(test994, SAMPLE2) {
  Solution sol;
  std::vector<std::vector<int>> oranges{
      std::vector<int>{2, 2}, std::vector<int>{1, 1}, std::vector<int>{0, 0},
      std::vector<int>{2, 0}};
  EXPECT_EQ(sol.orangesRotting(oranges), 1);
}