/**
 * @author Anti
 * @date 2023/11/7
 * @see https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
  bool isVowelCharacter(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }

 public:
  int vowelStrings(std::vector<std::string>& words, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; ++i) {
      size_t len = words[i].length();
      if (isVowelCharacter(words[i][0]) &&
          isVowelCharacter(words[i][len - 1])) {
        count++;
      }
    }
    return count;
  }
};  // fill in it

TEST(test2586, SAMPLE1) {
  Solution sol;
}

TEST(test2586, SAMPLE2) {
  Solution sol;
}