/**
 * @author Anti
 * @date 2023-12-29
 * @see https://leetcode.cn/problems/buy-two-chocolates
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int buyChoco(std::vector<int>& prices, int money) {
        int m1 = prices[0],m2 = prices[1];
        if(m1 > m2) {
          std::swap(m1,m2);
        }
        int n = prices.size();
        for(int i = 2; i < n ;i++) {
          if(prices[i] <= m1) {
            m2 = m1;
            m1 = prices[i];
          }
          else if(prices[i] < m2) {
            m2 = prices[i];
          }
        }
        if(m1 + m2 > money) {
          return money;
        }
        return money- m1-m2;
  }
};  // buy-two-chocolates

TEST(test2706, SAMPLE1) {
  Solution sol;
  std::vector nums{1,2,2};
  EXPECT_EQ(sol.buyChoco(nums,3),0);
}

TEST(test2706, SAMPLE2) {
  Solution sol;
  std::vector nums{98,54,6,34,66,63,52,39};
  EXPECT_EQ(sol.buyChoco(nums,62), 22);
}