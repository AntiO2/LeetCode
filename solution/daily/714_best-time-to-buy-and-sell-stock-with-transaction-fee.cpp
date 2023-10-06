//
// Created by Anti on 2023/10/6.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        auto n = int(prices.size());
        if (n<=0) {
            return 0;
        }
        int profit[n][2];
        profit[0][0]= -prices[0];
        profit[0][1] = 0; // 未持有股票
        for (int i = 1; i < n; i++) {
            profit[i][0] = std::max(profit[i-1][0],profit[i-1][1]-prices[i]);
            profit[i][1] = std::max(profit[i-1][1],profit[i-1][0]+prices[i]-fee);
        }
        return profit[n-1][1];
    }
};

TEST(test714,SAMPLE1) {
    Solution s;
    std::vector<int> ps  {1, 3, 2, 8, 4, 9};
    int fee =2;
    int ans = 8;
    EXPECT_EQ(s.maxProfit(ps,fee),ans);
}

TEST(test714,SAMPLE2) {
    Solution s;
    std::vector<int> ps  {1,3,7,5,10,3};
    int fee =3;
    int ans = 6;
    EXPECT_EQ(s.maxProfit(ps,fee),ans);
}