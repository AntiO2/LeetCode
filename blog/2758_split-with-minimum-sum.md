# [LeetCode] 贪心 2758 split-with-minimum-sum

## 题目

给你一个正整数 `num` ，请你将它分割成两个非负整数 `num1` 和 `num2` ，满足：`num1`和`num2`直接连起来，得到 `num`各数位的一个排列。

- 换句话说，`num1` 和 `num2` 中所有数字出现的次数之和等于 `num` 中所有数字出现的次数。

- `num1` 和 `num2` 可以包含前导 0 。

请你返回 `num1` 和 `num2` 可以得到的和的 **最小** 值。

**注意：**

- `num` 保证没有前导 0 。
- `num1` 和 `num2` 中数位顺序可以与 `num` 中数位顺序不同。

 

**示例 1：**

```
输入：num = 4325
输出：59
解释：我们可以将 4325 分割成 num1 = 24 和 num2 = 35 ，和为 59 ，59 是最小和。
```

**示例 2：**

```
输入：num = 687
输出：75
解释：我们可以将 687 分割成 num1 = 68 和 num2 = 7 ，和为最优值 75 。
```

## 思路



答案也即 Σ位权重*位数字。

比如4325，可以获得答案是
$$
5*10^0+4*10^0+3*10^1+2*10^1 = 59
$$
可以证明：应该尽量把大的数字放在低位，否则答案不是最小值，具体数字如何排列组合成两个数字是不用管的，只用知道它在哪一位上就好了。

1. 首先统计所有出现数字的次数。（使用一个长度为10的数组统计）
2. 从9遍历到1（0对答案和没有影响），使用一个变量pow统计目前在第几位的权重，当当前位放了两个数字后，pow*=10。

## 代码

```c++
//
// Created by Anti on 2023/10/9.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
public:
    int splitNum(int num) {
        short cnt[10];
        memset(cnt,0,sizeof (cnt));
        while(num) {
            ++cnt[num%10]; // 统计数字出现次数
            num/=10;
        }
        bool book = 0; // book = 0, 分配给第一个数字，book=1,分配给第二个数字
        int pow = 1;
        int ans = 0;
        for(int i = 9; i; --i) {
            for(int j = 0; j < cnt[i]; ++j) {
                ans+=pow*i;
                if(book) {
                    book = false;
                    pow*=10;
                } else {
                    book = true;
                }
            }
        }
        return ans;
    }
};

TEST(test2758,SAMPLE1) {
    Solution s;
    EXPECT_EQ(s.splitNum(4325),59);
}

TEST(test2758,SAMPLE2) {
    Solution s;
    EXPECT_EQ(s.splitNum(687),75);
}
```