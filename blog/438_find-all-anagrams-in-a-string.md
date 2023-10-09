# [LeetCode] 滑动窗口 438_find-all-anagrams-in-a-string.cpp

## 题目

[438. 找到字符串中所有字母异位词 - 力扣（LeetCode）](https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/?envType=study-plan-v2&envId=top-100-liked)

给定两个字符串 `s` 和 `p`，找到 `s` 中所有 `p` 的 **异位词** 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

**异位词** 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

**示例 1:**

```
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
```

 **示例 2:**

```
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
```

 

**提示:**

- `1 <= s.length, p.length <= 3 * 10^4`
- `s` 和 `p` 仅包含小写字母

## 思路

- 要找到p的异位词，假设异位词为p',那么len(p')=len(p),可以遍历s的位置作为p'的左端点，时间复杂度为$O(n*f(\text{判断指定子串是否为异位词}))$

- 由看到提示：`s` 和 `p` 仅包含小写字母，可以使用一个长度为26的计数器数组，判断每个字符串的出现次数是否相同。$\Theta(f(\text{判断指定子串是否为异位词}))=26$
- 剪枝：如果在`s`的位置`i`出现了字符$s[i]\notin p$ ,那么包含i的子串一定不是p的异位词，下一个查找子串开始的位置跳到`i+1`

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
private:
    /**
     * 统计s[pos,pos+len-1] 中字符的出现次数
     * @param pos
     * @param len
     * @param s
     * @param counter
     */
    auto count_string_char(int pos, int len, const std::string &s, int* counter) ->void {
        for(int i = 0; i < len; i++) {
            ++counter[s[pos+i]-'a'];
        }
    }
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        int p_len = int(p.length());
        int s_len = int(s.length());
        std::vector<int> ans;
        if(p_len > s_len) {
            return ans;
        }
        int cnt_s[26]{0};
        int cnt_p[26]{0};
        count_string_char(0, p_len, p, cnt_p);
        const int max_l = s_len - p_len;
        int left = 0;
        int right = 0;
        while(left<=max_l) {
            int target_pos = left + p_len - 1; // 目标right的位置（包含）
            while(right <= target_pos) {
                auto c = s[right];
                if(cnt_p[c-'a']==0) {
                    left = right + 1;
                    right = left;
                    memset(cnt_s, 0 ,sizeof (cnt_s));
                    break ;
                }
                ++cnt_s[c-'a'];
                if(right==target_pos) {
                    // 判断s[left, right]是否为异位词
                    int i = 0;
                    while(i < 26) {
                        if(cnt_s[i]!=cnt_p[i]) {
                            break ;
                        }
                        ++i;
                    }
                    if(i==26) {
                        ans.emplace_back(left);
                    }
                    --cnt_s[s[left]-'a'];
                    ++left;
                }
                ++right;
            }
        }
        return ans;
    }
};

TEST(test438,SAMPLE1) {
    Solution s;
    std::vector<int> ans = {0,6};
    EXPECT_EQ(s.findAnagrams("cbaebabacd", "abc"), ans);
}

TEST(test438,SAMPLE2) {
    Solution s;
    std::vector<int> ans = {0,1,2};
    EXPECT_EQ(s.findAnagrams("abab", "ab"), ans);
}
```

## 优化

官方题解的优化：

可以通过存储s子串和p每个字母出现次数的差额，并维护一个diff