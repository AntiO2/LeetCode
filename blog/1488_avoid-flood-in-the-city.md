# [LeetCode] 1488_avoid-flood-in-the-city

## 思路

[1488. 避免洪水泛滥 - 力扣（LeetCode）](https://leetcode.cn/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2023-10-13)



可以这样思考：初始所有状态都是0，`rain[i]`指示在`i`天，对`rain[i]`进行状态改变：

- `rain[i] ==1`

  - 如果`rain[i]`此时为0，变化为1

  - 如果`rain[i]`此时为1
    - 找前面没下雨的一天记为j , 且`j < i`，抽`rain[i]`的水，但是`rain[i]`相当于从1到0再到1, 可以发现其实状态是没有变化的。
    - 就可以加入一个`unordered_map`, 表示该湖在第几天变为了装满水的。
    - 如果前面没有可供抽水的一天，就不存在答案了。
  - `ans[i]=-1`

- `rain[i] ==0`
  - 将当前的天数加入一个队列，等待使用该天抽水。

接下来，我们要想一个抽水策略：

首先，抽水的那天k一定是`j < k < i`， 可以想到，k越靠近j越好。因为考虑这种情况:`102012`,如果1优先使用了第二个0，会导致2溢出。

具体推导是：

- 首先k一定满足`j < k < i`, 且`rain[i]`是此时唯一一个需要处理的湖（其他的湖已经安全），如果往后推k，可能存在`a' < k < i < a'` ，且`rain[a]=rain[a'] >0`,





## 代码

```c++
//
// Created by Anti on 2023/10/13.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
class Solution {
private:
public:
    std::vector<int> avoidFlood(std::vector<int> &rains) {
        std::unordered_map<int, int> rainy_day;
        std::set<int> free_day;
        int day_num = int(rains.size());
        bool success = true;
        std::vector ans(day_num, 1);

        for (int i = 0; i < day_num; ++i) {
            auto r = rains[i];
            if (r) {
                ans[i] = -1;
                auto iter = rainy_day.find(r);
                if (iter != rainy_day.end()) {
                    auto prev_day = iter->second;
                    auto lower = free_day.lower_bound(prev_day);
                    if (lower == free_day.end()) {
                        success = false;
                        break;
                    }
                    ans[*lower] = r;
                    free_day.erase(lower);
                }
                rainy_day[r] = i;
            } else {
                free_day.emplace(i);
            }
        };
        return success ? ans : std::vector<int>();
    }
};

TEST(test1488, SAMPLE1) {
    Solution s;
    std::vector rains{1, 2, 3, 4};
    std::vector ans{-1, -1, -1, -1};

    EXPECT_EQ(s.avoidFlood(rains), ans);
    LOG_INFO("SAMPLE1 PASS");
}

TEST(test1488, SAMPLE2) {
    Solution s;
    std::vector rains{1, 2, 0, 0, 2, 1};
    std::vector ans{-1, -1, 2, 1, -1, -1};
    EXPECT_EQ(s.avoidFlood(rains), ans);
    LOG_INFO("SAMPLE2 PASS");
}

TEST(test1488, SAMPLE3) {
    Solution s;
    std::vector rains{1, 2, 0, 1, 2};
    std::vector<int> ans{};
    EXPECT_EQ(s.avoidFlood(rains), ans);
    LOG_INFO("SAMPLE3 PASS");
}
TEST(test1488, SAMPLE4) {
    Solution s;
    std::vector rains{0, 1, 1};
    std::vector<int> ans{};
    EXPECT_EQ(s.avoidFlood(rains), ans);
    LOG_INFO("SAMPLE4 PASS");
}
TEST(test1488, SAMPLE5) {
    Solution s;
    std::vector rains{1, 1, 0, 0};
    std::vector<int> ans{};
    EXPECT_EQ(s.avoidFlood(rains), ans);
}
TEST(test1488, SAMPLE6) {
    Solution s;
    std::vector rains{0, 72328, 0, 0, 94598, 54189, 39171, 53361, 0, 0, 0, 72742, 0, 98613, 16696, 0, 32756, 23537, 0, 94598, 0, 0, 0, 11594, 27703, 0, 0, 0, 20081, 0, 24645, 0, 0, 0, 0, 0, 0, 0, 2711, 98613, 0, 0, 0, 0, 0, 91987, 0, 0, 0, 22762, 23537, 0, 0, 0, 0, 54189, 0, 0, 87770, 0, 0, 0, 0, 27703, 0, 0, 0, 0, 20081, 16696, 0, 0, 0, 0, 0, 0, 0, 35903, 0, 72742, 0, 0, 0, 35903, 0, 0, 91987, 76728, 0, 0, 0, 0, 2711, 0, 0, 11594, 0, 0, 22762, 24645, 0, 0, 0, 0, 0, 53361, 0, 87770, 0, 0, 39171, 0, 24577, 0, 0, 0, 24577, 0, 0, 72328, 0, 0, 32756, 0, 0, 76728};
    std::vector<int> ans{1, -1, 72328, 1, -1, -1, -1, -1, 94598, 54189, 53361, -1, 72742, -1, -1, 98613, -1, -1, 23537, -1, 16696, 39171, 32756, -1, -1, 27703, 11594, 1, -1, 20081, -1, 24645, 1, 1, 1, 1, 1, 1, -1, -1, 2711, 1, 1, 1, 1, -1, 91987, 1, 1, -1, -1, 22762, 1, 1, 1, -1, 1, 1, -1, 87770, 1, 1, 1, -1, 1, 1, 1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, -1, 35903, -1, 1, 1, 1, -1, 1, 1, -1, -1, 76728, 1, 1, 1, -1, 1, 1, -1, 1, 1, -1, -1, 1, 1, 1, 1, 1, -1, 1, -1, 1, 1, -1, 1, -1, 24577, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1};
    EXPECT_EQ(s.avoidFlood(rains), ans);
}
TEST(test1488, SAMPLE7) {
    Solution s;
    std::vector rains{1, 0, 2, 3, 0, 1, 2};
    std::vector<int> ans{-1, 1, -1, -1, 2, -1, -1};
    EXPECT_EQ(s.avoidFlood(rains), ans);
}
TEST(test1488, SAMPLE8) {
    Solution s;
    std::vector rains{1, 0, 2, 0, 3, 0, 2, 0, 0, 0, 1, 2, 3};
    std::vector<int> ans{-1, 1, -1, 2, -1, 3, -1, 2, 1, 1, -1, -1, -1};
    EXPECT_EQ(s.avoidFlood(rains), ans);
}
TEST(test1488, SAMPLE9) {
    Solution s;
    std::vector rains{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56438, 0, 0, 76913, 0, 0, 53492, 0, 50824, 0, 0, 0, 0, 0, 0, 0, 0, 79212, 0, 0, 0, 0, 0, 0, 36713, 62045, 79212, 36713, 56438, 0, 0, 0, 62045, 0, 76913, 50824, 0, 0, 0, 0, 0, 53492, 0};
    std::vector<int> ans{};
    EXPECT_EQ(s.avoidFlood(rains), ans);
}
```



