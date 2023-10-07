# [LeetCode] 单调栈：901. 股票价格跨度

## 题目

[901. 股票价格跨度 - 力扣（LeetCode）](https://leetcode.cn/problems/online-stock-span/description/?envType=daily-question&envId=2023-10-07)

设计一个算法收集某些股票的每日报价，并返回该股票当日价格的 **跨度** 。

当日股票价格的 **跨度** 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。

- 例如，如果未来 7 天股票的价格是 `[100,80,60,70,60,75,85]`，那么股票跨度将是 `[1,1,1,2,1,4,6]` 。

实现 `StockSpanner` 类：

- `StockSpanner()` 初始化类对象。
- `int next(int price)` 给出今天的股价 `price` ，返回该股票当日价格的 **跨度** 。

 

**示例：**

```
输入：
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
输出：
[null, 1, 1, 1, 2, 1, 4, 6]

解释：
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // 返回 1
stockSpanner.next(80);  // 返回 1
stockSpanner.next(60);  // 返回 1
stockSpanner.next(70);  // 返回 2
stockSpanner.next(60);  // 返回 1
stockSpanner.next(75);  // 返回 4 ，因为截至今天的最后 4 个股价 (包括今天的股价 75) 都小于或等于今天的股价。
stockSpanner.next(85);  // 返回 6
```

 

**提示：**

- $1 \le price \le 10^5$
- 最多调用 `next` 方法 $10^4$  次

# 思路

1. 最朴素的思想：每次调用next，就往往回遍历。时间复杂度$O(n^2)$, 理论上可以，但是太呆滞。
2. 换个思路想，要找到一个连续的小于或等于今天价格的数，实际上就是要找到往之前的日子（数组往左）的第一个大于该天的数。
3. 使用循环不等式思想：假如我们目前3天是a,b,c。且a > b > c加入一个新的数d。
   - 如果d >= c ，那么对于之后的数e来说，c是什么已经不重要了，因为e往左查找大于e的数时，如果e >= d，那么e一定 大于等于c。e <d那么已经查找到答案。此时从队列末尾删除c，并循环这个过程（下一个就判断是否d>=b）。
   - 如果d < c，那么找到的最近的符合要求的日子就是d。
   - 可以看出来前两条规则一定可以维护队列的严格单调递减性。
   - 但是要注意一种特殊情况：就是股价递增，比如价格为1，2，3，4，5。按照上述操作，如果队列已经被弹空了，那么说明d一定大于等于之前所有的股价。答案为当前天数。
4. 其实这就是单调栈。因为我们对队列的操作只有从队列末尾弹出，或者加入队列末尾。并且我们判断时不需要对队列进行随机访问，只需要对队列尾部进行判断。所以可以用栈来进行操作。



# 代码

```c++
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
```