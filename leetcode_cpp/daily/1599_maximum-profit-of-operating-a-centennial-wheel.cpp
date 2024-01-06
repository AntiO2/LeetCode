/**
 * @author Anti
 * @date 2024-01-01
 * @see
 * https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int minOperationsMaxProfit(std::vector<int>& customers, int boardingCost, int runningCost) {
    int i = 0;
    int now = 0;
    int max = 0, ans = -1;
    for(i = 0; i < customers.size(); i++) {
      if(customers[i] > 4) {
        if(i == customers.size()-1) {
          customers.push_back(customers[i]-4);
        } else {
          customers[i+1] +=(customers[i] - 4);
        }
        customers[i] = 4;
      }
      now = now + customers[i]*boardingCost - runningCost;
      if(now > max) {
        max = now;
        ans = i + 1;
      }
    }

    return ans;
  }
};  // maximum-profit-of-operating-a-centennial-wheel

TEST(test1599, SAMPLE1) {
  Solution sol;
  std::vector nums{3,4,0,5,1};
  EXPECT_EQ(sol.minOperationsMaxProfit(nums,1,92),-1);
}

TEST(test1599, SAMPLE2) {
  Solution sol;
}