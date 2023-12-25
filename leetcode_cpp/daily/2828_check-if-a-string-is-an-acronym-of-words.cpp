/**
 * @author Anti
 * @date 2023-12-20
 * @see https://leetcode.cn/problems/check-if-a-string-is-an-acronym-of-words
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  bool isAcronym(std::vector<std::string>& words, std::string s) {
    if(words.size()!=s.length()) {
      return false;
    }
    for(int i = 0 ; i< s.length(); i++) {
      if(s[i]!=words[i][0]) {
        return false;
      }
    }
    return true;
  }
};  // check-if-a-string-is-an-acronym-of-words

TEST(test2828, SAMPLE1) {
  Solution sol;
}

TEST(test2828, SAMPLE2) {
  Solution sol;
}