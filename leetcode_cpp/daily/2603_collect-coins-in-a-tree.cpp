//
// Created by Anti on 2023/9/21.
//
#include <queue>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
using std::vector;
class Solution {
 public:
  int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    auto n = coins.size();
    std::vector<int> degree;
    std::vector<std::vector<int>>
        link;  // link[x] = {y,z}, 表示从x连到y和z的边。
    degree.resize(n);
    link.resize(n);

    // 构建树
    for (auto& edge : edges) {
      auto x = edge[0];
      auto y = edge[1];
      degree[x]++;
      degree[y]++;
      link[x].emplace_back(y);
      link[y].emplace_back(x);
    }
    std::queue<int> deleted;
    for (size_t i = 0; i < n; i++) {
      if (degree[i] == 1 && !coins[i]) {
        deleted.emplace(i);
      }
    }
    auto rest = n;

    while (!deleted.empty()) {
      auto d = deleted.front();
      deleted.pop();
      --degree[d];
      rest--;
      for (auto& y : link[d]) {
        if (--degree[y] == 1 && !coins[y]) {
          deleted.emplace(y);
        }
      }
    }
    for (int k = 0; k < 2; k++) {
      // 连删两层叶结点.
      for (size_t i = 0; i < n; ++i) {
        if (degree[i] == 1) {
          deleted.emplace(i);
        }
      }
      while (!deleted.empty()) {
        auto d = deleted.front();
        deleted.pop();
        --degree[d];
        --rest;
        for (auto& y : link[d]) {
          --degree[y];
        }
      }
    }
    return rest == 0 ? 0 : (int(rest) - 1) * 2;
  }
};

TEST(test2603, SAMPLE1) {
  vector<int> coins = {1, 0, 0, 0, 0, 1};
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
  Solution s;
  EXPECT_EQ(s.collectTheCoins(coins, edges), 2);
}

TEST(test2603, SAMPLE2) {
  Solution s;
  vector<int> coins = {0, 0, 0, 1, 1, 0, 0, 1};
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4},
                               {2, 5}, {5, 6}, {5, 7}};
  EXPECT_EQ(s.collectTheCoins(coins, edges), 2);
}
TEST(test2603, TRICK1) {
  Solution s;
  vector<int> coins = {1, 1};
  vector<vector<int>> edges = {{0, 1}};
  EXPECT_EQ(s.collectTheCoins(coins, edges), 0);
}