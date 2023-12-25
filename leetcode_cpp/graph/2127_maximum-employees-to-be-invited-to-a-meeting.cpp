/**
 * @author Anti
 * @date 2023/11/1
 * @see
 * https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting
 */

#include <queue>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int maximumInvitations(std::vector<int>& favorite) {
    auto n = favorite.size();
    std::vector<int> inDegree(n, 0);
    std::vector<int> used(n, false);  // 可以被安排的员工
    std::vector<int> path(n, 1);      // 路径长度
    std::queue<int> q;                // 没有前置结点的（入度为0）
    // 因为一个节点不能指向自己，所以一定能形成环。
    for (auto& out : favorite) {
      ++inDegree[out];
    }
    for (int i = 0; i < n; ++i) {
      if (!inDegree[i]) {
        q.emplace(i);
      }
    }
    while (!q.empty()) {
      auto i = q.front();
      q.pop();
      used[i] = true;
      auto j = favorite[i];
      path[j] = std::max(path[j], path[i] + 1);
      if (!--inDegree[j]) {
        q.emplace(j);
      }
    }
    int double_direction = 0, single_ring = 0;
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        auto j = favorite[i];
        if (favorite[j] == i) {
          // 可以存在两条路径
          double_direction += (path[i] + path[j]);
          used[i] = used[j] = true;
        } else {
          used[i] = true;
          int cnt = 1;
          while (j != i) {
            used[j] = true;
            j = favorite[j];
            ++cnt;
          }
          single_ring = std::max(single_ring, cnt);
        }
      }
    }
    return std::max(double_direction, single_ring);
  }
};

TEST(test2127, SAMPLE1) {
  Solution sol;
  std::vector f{2, 2, 1, 2};
  int ans = 3;
  EXPECT_EQ(sol.maximumInvitations(f), ans);
}

TEST(test2127, SAMPLE2) {
  Solution sol;
  std::vector f{1, 2, 0};
  int ans = 3;
  EXPECT_EQ(sol.maximumInvitations(f), ans);
}

TEST(test2127, SAMPLE3) {
  Solution sol;
  std::vector f{3, 0, 1, 4, 1};
  int ans = 4;
  EXPECT_EQ(sol.maximumInvitations(f), ans);
}

TEST(test2127, SAMPLE4) {
  Solution sol;
  std::vector f{1, 0, 0, 2, 1, 4, 7, 8, 9, 6, 7, 10, 8};
  int ans = 6;
  EXPECT_EQ(sol.maximumInvitations(f), ans);
}

TEST(test2127, SAMPLE5) {
  Solution sol;
  std::vector f{1, 0, 3, 2, 5, 6, 7, 4, 9, 8, 11, 10, 11, 12, 10};
  int ans = 11;
  EXPECT_EQ(sol.maximumInvitations(f), ans);
}
