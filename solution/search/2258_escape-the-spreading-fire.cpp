/**
 * @author Anti
 * @date 2023/11/9
 * @see https://leetcode.cn/problems/escape-the-spreading-fire
 */
#include <vector>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

 public:
  int maximumMinutes(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = -1;
    auto bfs =
        [&](std::vector<std::pair<int, int>>& q) -> std::tuple<int, int, int> {
      std::vector<std::vector<int>> time(m, std::vector<int>(n, -1));
      for (auto& [i, j] : q) {
        time[i][j] = 0;  // bfs的源点。
      }
      for (int t = 1; !q.empty(); t++) {
        std::vector<std::pair<int, int>> nq;
        for (auto& [i, j] : q) {
          // 下一秒
          for (auto& [dx, dy] : dir) {
            int x = i + dx, y = j + dy;
            if (x < 0 || x >= m || y < 0 || y >= n || time[x][y] != -1 ||
                grid[x][y] != 0) {
              continue;
            }
            time[x][y] = t;
            nq.emplace_back(x, y);
          }
        }
        q = std::move(nq);
      }
      return std::tuple{time[m - 1][n - 1], time[m - 1][n - 2],
                        time[m - 2][n - 1]};
    };
    std::vector<std::pair<int, int>> q{std::make_pair(0, 0)};
    auto [man_arrive_time, man_left, man_up] = bfs(q);
    if (man_arrive_time < 0) {
      return -1;
    }
    std::vector<std::pair<int, int>> fire_pos;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          fire_pos.emplace_back(i, j);
        }
      }
    }
    auto [fire_arrive_time, fire_left, fire_up] = bfs(fire_pos);
    if (fire_arrive_time < 0) {
      return 1e9;
    }
    auto d = fire_arrive_time - man_arrive_time;
    if (d < 0) {
      return -1;
    }
    if ((man_left != -1 && man_left + d < fire_left) ||
        (man_up != -1 && man_up + d < fire_up)) {
      return d;
    }
    return d - 1;
  }
};  // escape-the-spreading-fire

TEST(test2258, SAMPLE1) {
  Solution sol;
  std::vector<std::vector<int>> grid{std::vector<int>{0, 2, 0, 0, 0, 0, 0},
                                     std::vector<int>{0, 0, 0, 2, 2, 1, 0},
                                     std::vector<int>{0, 2, 0, 0, 1, 2, 0},
                                     std::vector<int>{0, 0, 2, 2, 2, 0, 2},
                                     std::vector<int>{0, 0, 0, 0, 0, 0, 0}};
  EXPECT_EQ(sol.maximumMinutes(grid), 3);
}

TEST(test2258, SAMPLE2) {
  Solution sol;
}