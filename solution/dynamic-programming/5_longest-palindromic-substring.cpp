/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/longest-palindromic-substring
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::string longestPalindrome(std::string s) {
    int max = 0;
    int n = s.length();
    std::string ans;
    for (int i = 0; i < n; i++) {
      // 奇数个中心的情况。
      auto len = 1;
      auto left = i, right = i;
      while (--left >= 0 && ++right < n && s[left] == s[right]) {
        len += 2;
      }
      if (len > max) {
        max = len;
        ans = s.substr(left + 1, len);
      }
      // 回文串是偶数的情况
      left = i;
      right = i + 1;
      if (right < n && s[left] == s[right]) {
        len = 2;
        while (--left >= 0 && ++right < n && s[left] == s[right]) {
          len += 2;
        }
        if (len > max) {
          max = len;
          ans = s.substr(left + 1, len);
        }
      }
    }
    return ans;
  }
};

TEST(test5, SAMPLE1) {
  Solution sol;
  std::string s = "babad";
  std::string ans = "bab";
  EXPECT_EQ(sol.longestPalindrome(s), ans);
}

TEST(test5, SAMPLE2) {
  Solution sol;
}