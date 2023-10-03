//
// Created by Anti on 2023/10/2.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        auto n = prices.size();
        int profit[n][2];
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        for (int i = 1; i<n; ++i) {
            profit[i][0] = std::max(profit[i-1][0] , profit[i-1][1]+prices[i]);
            profit[i][1] = std::max(profit[i-1][1], profit[i-1][0]-prices[i]);
        }
        return profit[n-1][0];
    }
};

TEST(test122,SAMPLE1) {
    Solution s;
    std::vector<int> p{7,1,5,3,6,4};
    EXPECT_EQ(s.maxProfit(p), 7);
}

TEST(test122,SAMPLE2) {
    Solution s;
    std::vector<int> p{1,2,3,4,5};
    EXPECT_EQ(s.maxProfit(p), 4);
}