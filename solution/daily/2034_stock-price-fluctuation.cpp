//
// Created by Anti on 2023/10/8.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <queue>
class StockPrice {
private:

    std::unordered_map<int, int> prices_;

    struct min_stock_info {
        int timestamp,price;
        min_stock_info(int t, int p): timestamp(t),price(p){}
        bool operator< (const min_stock_info &b) const {
            return price > b.price;
        }
    };
    struct max_stock_info {
        int timestamp,price;
        max_stock_info(int t, int p): timestamp(t),price(p){}
        bool operator< (const max_stock_info &b) const {
            return price < b.price;
        }
    };
    std::priority_queue<min_stock_info> min_queue_;
    std::priority_queue<max_stock_info> max_queue_;
    int current_max_time_ = -1;
    int current_price_ = -1;
public:
    StockPrice() {

    }
    void update(int timestamp, int price) {
        prices_[timestamp] = price;
        max_queue_.emplace(timestamp, price);
        min_queue_.emplace(timestamp, price);
        if (timestamp >= current_max_time_) {
            current_max_time_ = timestamp;
            current_price_ = price;
        }
    }

    int current() {
        return current_price_;
    }

    int maximum() {
        while(prices_[max_queue_.top().timestamp]!=max_queue_.top().price) {
            max_queue_.pop();
        }
        return max_queue_.top().price;
    }
    int minimum() {
        while(prices_[min_queue_.top().timestamp]!=min_queue_.top().price) {
            min_queue_.pop();
        }
        return min_queue_.top().price;
    }
};
class StockPrice2 {
private:
    std::unordered_map<int, int> prices_;
    std::multiset<int> prices_set_;
    int current_max_time_ = -1;
    int current_price_ = -1;
public:
    StockPrice2() {

    }

    void update(int timestamp, int price) {
        auto iter = prices_.find(timestamp);
        if (iter!=prices_.end()) {
            auto old_price = iter->second;
            auto price_set_iter_ = prices_set_.find(old_price);
            if (price_set_iter_!=prices_set_.end()) {
                prices_set_.erase(price_set_iter_);
            }
        }

        prices_[timestamp] = price;
        prices_set_.emplace(price);
        if (timestamp >= current_max_time_) {
            current_max_time_ = timestamp;
            current_price_ = price;
        }
    }

    int current() {
        return current_price_;
    }

    int maximum() {
        return *prices_set_.rbegin();
    }

    int minimum() {
        return *prices_set_.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

TEST(test2034,SAMPLE1) {
    StockPrice stockPrice;
    stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
    stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
    EXPECT_EQ(stockPrice.current(), 5);     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
    EXPECT_EQ(stockPrice.maximum(), 10);     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
    stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。
                             // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
    EXPECT_EQ(stockPrice.maximum(), 5);     // 返回 5 ，更正后最高价格为 5 。
    stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
    EXPECT_EQ(stockPrice.minimum(), 2);     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
}
