//
// Created by Anti on 2023/10/3.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
/**
 * 最多只能进行2次交易，也就是说有五种状态。
 * -1: 未交易, 该状态的收益是永远不变的，为0
 * 0：第一次买入
 * 1：第一次卖出
 * 2：第二次买入
 * 3：第二次卖出
 */
class Solution {
 public:
  /**
   *
   * @param prices
   * @return
   */
  int maxProfit(std::vector<int>& prices) {
    auto n = prices.size();
    int profit[n][4];
    profit[0][0] = -prices[0];
    profit[0][1] = 0;
    profit[0][2] = -prices[0];
    profit[0][3] = 0;
    for (int i = 1; i < n; ++i) {
      profit[i][0] = std::max(profit[i - 1][0], -prices[i]);
      profit[i][1] = std::max(profit[i - 1][1], profit[i - 1][0] + prices[i]);
      profit[i][2] = std::max(profit[i - 1][2], profit[i - 1][1] - prices[i]);
      profit[i][3] = std::max(profit[i - 1][3], profit[i - 1][2] + prices[i]);
    }
    return std::max(profit[n - 1][1], profit[n - 1][3]);
  }
};

TEST(test123, SAMPLE1) {
  Solution s;
  std::vector<int> p{3, 3, 5, 0, 0, 3, 1, 4};
  EXPECT_EQ(s.maxProfit(p), 6);
}

TEST(test123, SAMPLE2) {
  Solution s;
  std::vector<int> p{1, 2, 3, 4, 5};
  EXPECT_EQ(s.maxProfit(p), 4);
}

TEST(test123, SAMPLE3) {
  Solution s;
  std::vector<int> p{7, 6, 4, 3, 1};
  EXPECT_EQ(s.maxProfit(p), 0);
}
TEST(test123, SAMPLE4) {
  Solution s;
  std::vector<int> p{1};
  EXPECT_EQ(s.maxProfit(p), 0);
}
