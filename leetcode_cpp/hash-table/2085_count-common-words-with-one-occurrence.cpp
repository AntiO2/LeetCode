/**
 * @author Anti
 * @date 2024-01-12
 * @see https://leetcode.cn/problems/count-common-words-with-one-occurrence
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2) {
    std::unordered_map<std::string ,int> cnt_1,cnt_2;
    for(auto&word:words1) {
      cnt_1[word]++;
    }
    for(auto&word:words2) {
      cnt_2[word]++;
    }
    int ans = 0;
    for(auto&[word,cnt]:cnt_1) {
      if(cnt==1&&cnt_2[word]==1) {
        ans++;
      }
    }
    return ans;
  }
};  // count-common-words-with-one-occurrence

TEST(test2085, SAMPLE1) {
  Solution sol;
}

TEST(test2085, SAMPLE2) {
  Solution sol;
}