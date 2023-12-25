/**
 * @author Anti
 * @date 2023/11/8
 * @see
 * https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int findTheLongestBalancedSubstring(std::string s) {
    int ans = 0;
    int cnt_zero = 0;
    int cnt_one = 0;
    auto iter = s.begin();
    int status = 0;
    while (iter != s.end()) {
      if (status == 0 && *iter == '0') {
        ++cnt_zero;
      } else if (status == 0 && *iter == '1') {
        ++cnt_one;
        status = 1;
      } else if (status == 1 && *iter == '1') {
        ++cnt_one;
      } else if (status == 1 && *iter == '0') {
        // 结算
        ans = std::max(ans, std::min(cnt_one, cnt_zero));
        cnt_one = 0;
        cnt_zero = 1;
        status = 0;
      }
      ++iter;
    }
    if (status == 1) {
      ans = std::max(ans, std::min(cnt_one, cnt_zero));
    }
    return ans * 2;
  }
};

TEST(test2609, SAMPLE1) {
  Solution sol;
  std::string s{"01000111"};
  EXPECT_EQ(sol.findTheLongestBalancedSubstring(s), 6);
}

TEST(test2609, SAMPLE2) {
  Solution sol;
  std::string s{"001"};
  EXPECT_EQ(sol.findTheLongestBalancedSubstring(s), 2);
}