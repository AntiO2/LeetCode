/**
 * @author Anti
 * @date 2023-12-07
 * @see
 * https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
using namespace std; //
class Solution {
 private:
  enum type_t{TO,FROM};
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    std::vector<std::vector<std::pair<int,type_t>>> g(n);
    for(auto &conn:connections) {
      g[conn[0]].emplace_back(conn[1],TO);
      g[conn[1]].emplace_back(conn[0],FROM);
    }
    int ans = 0;
    std::vector<bool> visited(n,false);
    function<void(int)> dfs = [&](int now) {
      visited[now] = true;
      for(auto&line:g[now]) {
        auto dst = line.first;
        auto type = line.second;
        if(visited[dst]) {
          continue;
        }
        if(type==TO) {
          ++ans;
        }
        dfs(dst);
      }
    };
    dfs(0);
    return ans;
  }
};  // reorder-routes-to-make-all-paths-lead-to-the-city-zero

TEST(test1466, SAMPLE1) {
  Solution sol;
  std::vector<std::vector<int>> g = {
      std::vector<int>{0,1},
      std::vector<int>{1,3},
      std::vector<int>{2,3},
      std::vector<int>{4,0},
      std::vector<int>{4,5},
  };
  EXPECT_EQ(sol.minReorder(6,g),3);
}

TEST(test1466, SAMPLE2) {
  Solution sol;
}