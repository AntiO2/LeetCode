//
// Created by Anti on 2023/10/9.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"
#include <list>
#include <unordered_set>
class Solution {
private:
    std::unordered_set<char> char_set_;

public:
    int lengthOfLongestSubstring(std::string s) {
        char_set_.clear();
        int length = s.length();
        if (length == 0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int ans = 1;
        char_set_.emplace(s[0]);
        while (right < length) {
            ++right;
            auto c = s[right];
            if (char_set_.count(c)) {
                ans = std::max(right - left, ans);
                while (left < right) {
                    if (s[left] == c) {
                        break;
                    } else {
                        char_set_.erase(s[left]);
                    }
                    ++left;
                }
                ++left;// 找到重复字符的下一个地方
            } else {
                char_set_.emplace(c);
            }
        }
        ans = std::max(ans, right - left);
        return ans;
    }
};

TEST(test3, SAMPLE1) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(test3, SAMPLE2) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
}
TEST(test3, SAMPLE3) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}
TEST(test3, SAMPLE4) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcde"), 5);
}

TEST(test3, SAMPLE5) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("tmmzuxt"), 5);
}