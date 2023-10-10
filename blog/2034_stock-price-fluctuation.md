# [LeetCode] [2034. 股票价格波动](https://leetcode.cn/problems/stock-price-fluctuation/)

## 题目

给你一支股票价格的数据流。数据流中每一条记录包含一个 **时间戳** 和该时间点股票对应的 **价格** 。

不巧的是，由于股票市场内在的波动性，股票价格记录可能不是按时间顺序到来的。某些情况下，有的记录可能是错的。如果两个有相同时间戳的记录出现在数据流中，前一条记录视为错误记录，后出现的记录 **
更正** 前一条错误的记录。

请你设计一个算法，实现：

- **更新** 股票在某一时间戳的股票价格，如果有之前同一时间戳的价格，这一操作将 **更正** 之前的错误价格。
- 找到当前记录里 **最新股票价格** 。**最新股票价格** 定义为时间戳最晚的股票价格。
- 找到当前记录里股票的 **最高价格** 。
- 找到当前记录里股票的 **最低价格** 。

请你实现 `StockPrice` 类：

- `StockPrice()` 初始化对象，当前无股票价格记录。
- `void update(int timestamp, int price)` 在时间点 `timestamp` 更新股票价格为 `price` 。
- `int current()` 返回股票 **最新价格** 。
- `int maximum()` 返回股票 **最高价格** 。
- `int minimum()` 返回股票 **最低价格** 。

**示例 1：**

```
输入：
["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
[[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
输出：
[null, null, null, 5, 10, null, 5, null, 2]

解释：
StockPrice stockPrice = new StockPrice();
stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
stockPrice.current();     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
stockPrice.maximum();     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。
                          // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
stockPrice.maximum();     // 返回 5 ，更正后最高价格为 5 。
stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
stockPrice.minimum();     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
```

**提示：**

- `1 <= timestamp, price <= 10^9`
- `update`，`current`，`maximum` 和 `minimum` **总** 调用次数不超过 `10^5` 。
- `current`，`maximum` 和 `minimum` 被调用时，`update` 操作 **至少** 已经被调用过 **一次**

## 思路1

> **更新** 股票在某一时间戳的股票价格，如果有之前同一时间戳的价格，这一操作将 **更正** 之前的错误价格。

容易想到使用hash表来存储时间-价格

> 找到当前记录里 **最新股票价格** 。**最新股票价格** 定义为时间戳最晚的股票价格。

最新的股票价格可以在每次update时更新，通过判断timestamp参数是不是最大的就行了。

> 找到当前记录里股票的 **最高价格** 。找到当前记录里股票的 **最低价格** 。

用一个有序多重集合维护股票价格。因为我们不需要返回是哪一天是价格最大或最小的，所以使用multiset就行。

```c++
class StockPrice {
private:
    std::unordered_map<int, int> prices_;
    std::multiset<int> prices_set_;
    int current_max_time_ = -1;
    int current_price_ = -1;
public:
    StockPrice() {

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

```

## 思路2

在这个题目中，一个难点是：如何在维护时间戳-价格的同时维护一个有序的数据结构。如果用堆的话，更新无法**立即**找到对应时间戳的信息。

但是可以换种想法：

比如要找最小的价格，还是每次取小根堆的顶，但是该顶部时间戳对应的价格可能已经更新，此时再去查对应的哈希表，如果价格变动，该结果就无效，弹出并取下一个值。

优先队列中可能存在相同时间戳的多个结点，但是对结果没有影响，因为可以通过哈希表分辨出该价格是否正确。

```c++
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
```