/**
 * @author Anti
 * @date 2023-12-05
 * @see https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  long long sum = 0;
  int dfs(int city, vector<vector<int>>& roads,int father,int seats) {
    auto size = 1;
    for(auto &dst:roads[city]) {
      if(dst!=father) {
        auto sub_size = dfs(dst, roads, city,seats);
        size+= sub_size;
        sum+=(sub_size+seats-1)/seats;
      }
    }
    return size;
  }
 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    auto n = roads.size()+1;
    std::vector<std::vector<int>> g(n);
    for(auto &road:roads) {
      g[road[0]].push_back(road[1]);
      g[road[1]].push_back(road[0]);
    }
    dfs(0,g,-1,seats);
    return sum;
  }
}; // minimum-fuel-cost-to-report-to-the-capital

TEST(test2477, SAMPLE1) {
  Solution sol;
}

TEST(test2477, SAMPLE2) {
  Solution sol;
}