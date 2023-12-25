/**
 * @author Anti
 * @date 2023-12-17
 * @see https://leetcode.cn/problems/min-cost-climbing-stairs
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int minCostClimbingStairs(std::vector<int>& cost) {
    auto n = cost.size();
    std::vector<int> cost_sum(n+1,0);
    for(int i = 2;i<=n;i++) {
      cost_sum[i] = std::min(cost_sum[i-2]+cost[i-2], cost_sum[i-1]+cost[i-1]);
    }
    return cost_sum[n];
  }
};  // min-cost-climbing-stairs

TEST(test746, SAMPLE1) {
  Solution sol;
}

TEST(test746, SAMPLE2) {
  Solution sol;
}