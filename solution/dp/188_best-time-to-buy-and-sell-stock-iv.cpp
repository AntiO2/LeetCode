//
// Created by Anti on 2023/10/4.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int maxProfit(int k, std::vector<int>& prices) {
    auto n = prices.size();
    int profit[k + 1][2][n];
    // profit[a][b][c]表示第a次交易，b = 0表示买入股票，
    // b=1表示卖出股票，c表示第c天。a=0表示未交易的状态。
    memset(profit, 0, sizeof(profit));
    for (size_t j = 1; j <= k; j++) {
      profit[j][0][0] = -prices[0];
    }
    for (size_t i = 1; i < n; i++) {
      for (size_t j = 1; j <= k; j++) {
        profit[j][0][i] =
            std::max(profit[j - 1][1][i - 1] - prices[i],
                     profit[j][0][i - 1]);  // 可以选择交易或不交易
        profit[j][1][i] =
            std::max(profit[j][0][i - 1] + prices[i], profit[j][1][i - 1]);
        // LOG_DEBUG("Day[%zu] Profit Buy:\t[%d]
        // \tTrade[%zu]",i,profit[j][0][i],j); LOG_DEBUG("Day[%zu] Profit
        // Sell:\t[%d] \tTrade[%zu]",i, profit[j][1][i],j);
      }
    }
    int ans = 0;
    for (size_t j = 1; j <= k; j++) {
      ans = std::max(ans, profit[j][1][n - 1]);
    }
    return ans;
  }
};
TEST(test188, SAMPLE1) {
  Solution s;
  std::vector<int> p{2, 4, 1};
  int k = 2;
  EXPECT_EQ(s.maxProfit(k, p), 2);
}

TEST(test188, SAMPLE2) {
  Solution s;

  std::vector<int> p{3, 2, 6, 5, 0, 3};
  int k = 2;
  EXPECT_EQ(s.maxProfit(k, p), 7);
}