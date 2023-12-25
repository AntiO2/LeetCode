/**
 * @author Anti
 * @date 2023/11/4
 * @see https://leetcode.cn/problems/palindrome-partitioning
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  std::vector<std::vector<bool>> is_palindromic_{};  // 某个子串是否为回文串
  std::vector<std::vector<std::string>> ans_;
  std::vector<std::string> curr_;
  /**
   *
   * @param s
   * @param k k是当前的位置
   */
  void dfs(std::string s, int k) {
    if (k == s.length()) {
      ans_.push_back(curr_);
    }
    for (int i = k; i < s.length(); ++i) {
      if (is_palindromic_[k][i]) {
        curr_.push_back(s.substr(k, i - k + 1));
        dfs(s, i + 1);
        curr_.pop_back();
      }
    }
  }

 public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    auto l = s.length();
    is_palindromic_.assign(l, std::vector<bool>(l, true));
    for (int i = l - 1; i >= 0; --i) {
      for (int j = i + 1; j < l; ++j) {
        is_palindromic_[i][j] = (s[i] == s[j]) && is_palindromic_[i + 1][j - 1];
      }
    }
    dfs(s, 0);
    return ans_;
  }
};

TEST(test131, SAMPLE1) {
  Solution sol;
  sol.partition("aab");
}

TEST(test131, SAMPLE2) {
  Solution sol;
}