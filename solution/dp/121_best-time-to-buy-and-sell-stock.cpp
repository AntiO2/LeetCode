//
// Created by Anti on 2023/10/1.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    auto buy = prices[0];
    auto ans = 0;
    for (auto& price : prices) {
      ans = std::max(ans, price - buy);
      buy = std::min(buy, price);
    }
    return ans;
  }
};

TEST(test121, SAMPLE1) {
  Solution s;
  std::vector<int> p{7, 1, 5, 3, 6, 4};
  EXPECT_EQ(s.maxProfit(p), 5);
}

TEST(test121, SAMPLE2) {
  Solution s;
  std::vector<int> p{7, 6, 4, 3, 1};
  EXPECT_EQ(s.maxProfit(p), 0);
}