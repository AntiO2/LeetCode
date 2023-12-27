/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/longest-palindromic-substring
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

// DP
class Solution {
 public:
  std::string longestPalindrome(std::string s) {
    if(s.empty()) {
      return "";
    }
    auto n = s.size();
    std::vector<std::vector<int>> dp(n,std::vector<int>(n));
    int max = 1;
    int ans_left = 0;
    for(int i = 0; i < n; i++) {
      dp[i][i] = 1;
      for(int j = i-1; j >=0; j--) {
        if(s[j]==s[i]&& (j==i-1||dp[j+1][i-1])) {
          dp[j][i] = dp[j+1][i-1] + 2;
          if(dp[j][i] > max) {
            max = dp[j][i];
            ans_left = j;
          }
        }
      }
    }
    return s.substr(ans_left,max);
  }
};
// 中心扩散法
class Solution2 {
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
  std::string s = "aacabdkacaa";
  std::string ans = "aca";
  EXPECT_EQ(sol.longestPalindrome(s), ans);
}