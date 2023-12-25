/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/word-break
 */

#include <unordered_set>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_map<std::string, int> book_table;
    for (const auto& word : wordDict) {
      book_table.emplace(word, word.length());
    }
    std::vector dp(s.length() + 1, false);
    dp[0] = true;
    for (int i = 0; i < s.length(); i++) {
      for (auto& [word, len] : book_table) {
        if (len > i + 1 || !dp[i + 1 - len])
          continue;
        if (s.substr(i - len + 1, len) == word) {
          dp[i + 1] = true;
        }
      }
    }
    return dp[s.length()];
  }
};  // word-break

TEST(test139, SAMPLE1) {
  Solution sol;
  std::string s{"leetcode"};
  std::vector<std::string> dict{"leet", "code"};
  EXPECT_EQ(sol.wordBreak(s, dict), true);
}

TEST(test139, SAMPLE2) {
  Solution sol;
  std::string s{"catsandog"};
  std::vector<std::string> dict{"cats", "dog", "sand", "and", "cat"};
  EXPECT_EQ(sol.wordBreak(s, dict), false);
}