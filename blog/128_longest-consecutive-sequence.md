## 题目描述

给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

 

**示例 1：**

```
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

**示例 2：**

```
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
```

 

**提示：**

- `0 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`

## 思考

第一反应：对`nums`进行排序，然后查找最大序列。

但是时间复杂度为$\Omicron (nlogn)$

然后想一下，可以枚举每个数字，比如x。然后查看`x+1`,`x+2`,`x+3`是否出现过。

朴素的话时间复杂度为$\Omicron (n^2)$

通过剪枝，如果处理`x`, 存在`x-1`的话，肯定不用进行这次遍历(因为结果肯定会小于从`x-1`开始)。时间复杂度$\Omicron (n)$

然后还可以使用并查集。比如`2,3,4`在同一个集合。`7,8,9,10`在一个集合。但是需要维护集合大小。

## 代码实现

感觉第三种实现比较有意思。虽然实际上写起来就感觉运行会很慢。权当复习并查集了

```C++
//
// Created by Anti on 2023/9/1.
//
#include "gtest/gtest.h"
#include "logger.h"

/**
 * @description 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 */
class Solution {
private:
    std::unordered_map<int,int> father_;
    std::unordered_map<int,size_t> size_; // 所在并查集的大小
    int max_size_{}; // 最大的并查集大小
    /**
     * 返回x的祖先。约定祖先较小。
     * @param x
     * @return
     */
    auto get_root(int x) -> int {
        if(father_[x]==x) {
            return x;
        }
        return father_[x] = get_root(father_[x]);
    }
public:
    int longestConsecutive(std::vector<int>& nums) {
        max_size_ = !nums.empty();
        for(const auto &num:nums) {
            father_[num] = num;
            size_[num] = 1;
        }
        for(const auto &num:nums) {
            auto y = num+1;
            if(father_.count(num+1)) {
                auto father_x = get_root(num);
                auto father_y = get_root(y); // 1 3 5 4
                if(father_x!=father_y) {
                    if(father_x > father_y) {
                        std::swap(father_x, father_y);
                    }
                    father_[father_y] = father_x;
                    size_[father_x] += size_[father_y];
                    max_size_ = std::max(max_size_, int(size_[father_x]));
                }
            }
        }
        return max_size_;
    }
};

TEST(S128,SAMPLE1) {
    Solution s;
    std::vector<int> nums = {100,4,200,1,3,2};
    EXPECT_EQ(s.longestConsecutive(nums),4);
}

TEST(S128,SAMPLE2) {
    Solution s;
    std::vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    EXPECT_EQ(s.longestConsecutive(nums),9);
}

TEST(S128,TRICK1) {
    Solution s;
    std::vector<int> nums = {0};
    EXPECT_EQ(s.longestConsecutive(nums),1);
}
TEST(S128,TRICK2) {
    Solution s;
    std::vector<int> nums = {};
    EXPECT_EQ(s.longestConsecutive(nums),0);
}
```