//
// Created by Anti on 2023/10/9.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"
#include <list>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        int p_len = int(p.length());
        int s_len = int(s.length());
        std::vector<int> ans;
        if (p_len > s_len) {
            return ans;
        }
        int cnt_s[26]{0};
        int cnt_p[26]{0};
        for (int i = 0; i < p_len; i++) {
            ++cnt_p[p[i] - 'a'];
        }
        const int max_l = s_len - p_len;
        int left = 0;
        int right = 0;
        while (left <= max_l) {
            int target_pos = left + p_len - 1;// 目标right的位置（包含）
            while (right <= target_pos) {
                auto c = s[right];
                if (cnt_p[c - 'a'] == 0) {
                    left = right + 1;
                    right = left;
                    memset(cnt_s, 0, sizeof(cnt_s));
                    break;
                }
                ++cnt_s[c - 'a'];
                if (right == target_pos) {
                    // 判断s[left, right]是否为异位词
                    int i = 0;
                    while (i < 26) {
                        if (cnt_s[i] != cnt_p[i]) {
                            break;
                        }
                        ++i;
                    }
                    if (i == 26) {
                        ans.emplace_back(left);
                    }
                    --cnt_s[s[left] - 'a'];
                    ++left;
                }
                ++right;
            }
        }
        return ans;
    }
};

TEST(test438, SAMPLE1) {
    Solution s;
    std::vector<int> ans = {0, 6};
    EXPECT_EQ(s.findAnagrams("cbaebabacd", "abc"), ans);
}

TEST(test438, SAMPLE2) {
    Solution s;
    std::vector<int> ans = {0, 1, 2};
    EXPECT_EQ(s.findAnagrams("abab", "ab"), ans);
}

/**
 * 作者：力扣官方题解
链接：https://leetcode.cn/problems/find-all-anagrams-in-a-string/
             来源：力扣（LeetCode）
                     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
using namespace std;
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);
        for (int i = 0; i < pLen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        int differ = 0;
        for (int j = 0; j < 26; ++j) {
            if (count[j] != 0) {
                ++differ;
            }
        }

        if (differ == 0) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            if (count[s[i] - 'a'] == 1) {// 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i] - 'a'] == 0) {// 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            --count[s[i] - 'a'];

            if (count[s[i + pLen] - 'a'] == -1) {// 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i + pLen] - 'a'] == 0) {// 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            ++count[s[i + pLen] - 'a'];

            if (differ == 0) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

TEST(test438, SAMPLE3) {
    Solution2 s;
    std::vector<int> ans = {0};
    EXPECT_EQ(s.findAnagrams("abb", "ab"), ans);
}