//
// Created by Anti on 2023/10/5.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

/**
 * 吐槽：股票买卖真是没完没了了。
 *
 */
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = (int) prices.size();
        int buy[n]; // 表示第i天，买入股票的收益
        int sell[n][2]; // 第i天卖出股票的收益，第二维表示是否进入冷冻期。买入股票无法从前一天的冷冻期转移。不能连续买入股票
        memset(sell,0,sizeof(sell));
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++) {
            buy[i] = std::max(buy[i-1],  sell[i-1][0]-prices[i]/*选择在这一天买股票*/);
            sell[i][0] = std::max(sell[i-1][0],sell[i-1][1]);
            sell[i][1] = buy[i-1] + prices[i];
        }
        auto ans = 0;
        for(int i = 0; i < n; i++) {
            ans = std::max(ans,std::max(sell[i][0],sell[i][1]));
        }
        return ans;
    }
};

TEST(test309,SAMPLE1) {
    Solution s;
    std::vector<int> ps  {1,2,3,0,2};
    EXPECT_EQ(s.maxProfit(ps), 3);
}

TEST(test309,SAMPLE2) {
    Solution s;
    std::vector<int> ps  {1};
    EXPECT_EQ(s.maxProfit(ps), 0);
}
TEST(test309,SAMPLE3) {
    Solution s;
    std::vector<int> ps  {1,2,4};
    EXPECT_EQ(s.maxProfit(ps), 3);
}