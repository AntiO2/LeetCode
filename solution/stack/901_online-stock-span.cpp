#include <list>
#include <stack>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class StockSpanner {
private:
    using stock_info_t = std::pair<int ,int>; // 第一个元素表示天数， 第二个元素表示股价
    std::stack<stock_info_t> stocks_;
    std::atomic<int> day_;
public:
    StockSpanner() :day_(0){};
    int next(int price) {
        ++day_;
        while(!stocks_.empty()) {
            auto prev_day = stocks_.top().first;
            auto prev_price = stocks_.top().second;
            if(stocks_.top().second > price) {
                stocks_.emplace(day_, price);
                return (day_-prev_day);
            } else {
                stocks_.pop();
            }
        }
        stocks_.emplace(day_, price);
        return day_;
    }
};

TEST(test901,SAMPLE1) {
    StockSpanner stockSpanner = StockSpanner();
    EXPECT_EQ(stockSpanner.next(100),1); // 返回 1
    EXPECT_EQ(stockSpanner.next(80),1);  // 返回 1
    EXPECT_EQ(stockSpanner.next(60),1);  // 返回 1
    EXPECT_EQ(stockSpanner.next(70),2);  // 返回 2
    EXPECT_EQ(stockSpanner.next(60),1);  // 返回 1
    EXPECT_EQ(stockSpanner.next(75),4);  // 返回 4 ，因为截至今天的最后 4 个股价 (包括今天的股价 75) 都小于或等于今天的股价。
    EXPECT_EQ(stockSpanner.next(85),6);  // 返回 6
}
TEST(test901,SAMPLE2) {
    StockSpanner stockSpanner = StockSpanner();
    EXPECT_EQ(stockSpanner.next(100),1); // 返回 1
    EXPECT_EQ(stockSpanner.next(101),2);  // 返回 2
    EXPECT_EQ(stockSpanner.next(102),3);  // 返回 3
    EXPECT_EQ(stockSpanner.next(103),4);  // 返回 4
}
