# [LeetCode] 滑动窗口 longest-substring-without-repeating-characters

## 题目

[3. 无重复字符的最长子串 - 力扣（LeetCode）](https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-100-liked)

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长子串** 的长度。

 

**示例 1:**

```
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

## 思路

- 类似于双指针的想法，首先left和right都取下标0，我们目前维护`s[left:right+1]`为无重复字符的子串。因为一开始只有一个字符，所以是满足特性的。

- 之后right向后推，直到遇到第一个重复的字符，维护答案为$max( ans, right- left)$ 。然后right维持不动，left向前直到找到第一个为s[right]的字符的下一个位置。这样，维护了该字符只出现一次。
- 但是如何证明这样找到的子串为最大的？反证： 假如这样的子串不是最大的，说明left向右移动多了，或者right向右移动少了。
  - 如果left向右移动多了：尝试将left向左回退，但是根据移动规则，s[left-1] = s[right]。出现重复字符，矛盾。
  - right向右移动少了：保持left不动，right是一直向右直到找到重复字符的。所以假设错误。同时，right是能保证遍历整个字符串的。也就是说，对于每个位置，都尝试将其作为右端点，并找到了其最长子串的left。
- 如何判断重复字符串？
  - 使用unordered set
  - 在right向右移动过程中，出现的新字符加入set
  - 如果出现出现过的字符c
    - left->right
    - 从集合中删除left向左移动的过程中，不再包含的字符
    - 一个小优化：当left找到了之前出现该字符的位置, 不需要删除，直接退出循环就行。因为s[right]还要将该字符加入集合。（省去先删除再加入同一个字符的操作）

## 代码

```c++
//
// Created by Anti on 2023/10/9.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <unordered_set>
class Solution {
private:
    std::unordered_set<char> char_set_;
public:
    int lengthOfLongestSubstring(std::string s) {
        char_set_.clear();
        int length = s.length();
        if(length==0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int ans = 1;
        char_set_.emplace(s[0]);
        while (right < length) {
            ++right;
            auto c = s[right];
            if(char_set_.count(c)) {
                ans = std::max(right-left, ans);
                while(left < right) {
                    if(s[left]==c) {
                        break ;
                    } else {
                        char_set_.erase(s[left]);
                    }
                    ++left;
                }
                ++left; // 找到重复字符的下一个地方
            } else {
                char_set_.emplace(c);
            }
        }
        ans = std::max(ans, right-left);
        return ans;
    }
};

TEST(test3,SAMPLE1) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(test3,SAMPLE2) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
}
TEST(test3,SAMPLE3) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}
TEST(test3,SAMPLE4) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcde"), 5);
}

TEST(test3,SAMPLE5) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("tmmzuxt"), 5);
}
```