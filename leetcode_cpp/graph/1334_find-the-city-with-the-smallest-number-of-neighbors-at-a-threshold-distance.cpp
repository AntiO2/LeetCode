/**
 * @author Anti
 * @date 2023/11/14
 * @see
 * https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int findTheCity(int n, std::vector<std::vector<int>>& edges,
                  int distanceThreshold) {
    std::vector<std::vector<int>> g(n, std::vector<int>(n, 10005));
    for (int i = 0; i < n; i++) {
      g[i][i] = 0;
    }
    for (const auto& e : edges) {
      int src = e[0], dst = e[1], dist = e[2];
      g[src][dst] = g[dst][src] = std::min(g[src][dst], dist);
    }
    floyd(g);
    int ans = -1, cnt = n;
    for (int i = 0; i < n; i++) {
      int curr = 0;
      for (int j = 0; j < n; j++) {
        if (j != i && g[i][j] <= distanceThreshold) {
          ++curr;
        }
      }
      if (curr <= cnt) {
        cnt = curr;
        ans = i;
      }
    }
    return ans;
  }

 private:
  void floyd(std::vector<std::vector<int>>& g) {
    int n = g.size();
    for (int p = 0; p < n; p++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          g[i][j] = std::min(g[i][j], g[i][p] + g[p][j]);
        }
      }
    }
  }

};  // find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

TEST(test1334, SAMPLE1) {
  Solution sol;
  int n = 4;
  int dt = 4;
  std::vector<std::vector<int>> edges{
      std::vector<int>{0, 1, 3}, std::vector<int>{1, 2, 1},
      std::vector<int>{1, 3, 4}, std::vector<int>{2, 3, 1}};
  EXPECT_EQ(sol.findTheCity(n, edges, dt), 3);
}

TEST(test1334, SAMPLE2) {
  Solution sol;
}