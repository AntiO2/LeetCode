/**
 * @author Anti
 * @date 2023-11-26
 * @see https://leetcode.cn/problems/b
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  inline bool  check(char c) {
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
      return true;
    }
    return false;
  }
 public:
  int beautifulSubstrings(std::string s, int k) {

    auto l = s.length();
    std::vector<int> prev_vowels(l + 1,0);
    std::vector<int> prev_consonants(l + 1,0);
    int prev_vo = 0, prev_con = 0;
    for(int i = 1 ;i <= l;i++) {
      if(check(s[i-1])) {
        ++prev_vo;
      } else {
        ++prev_con;
      }
      prev_vowels[i] = prev_vo;
      prev_consonants[i] = prev_con;
    }
    int ans = 0;
    for(int i = 0; i <= l;i++) {
      for(int j = 0; j < i;j++) {
        auto diff_c = prev_consonants[i]-prev_consonants[j], diff_v = prev_vowels[i]-prev_vowels[j];
        if(diff_c==diff_v&&(diff_c*diff_v)%k==0) {
          ++ans;
        }
      }
    }
    return ans;
  }
};

TEST(test2948, SAMPLE1) {
  Solution sol;
}

TEST(test2948, SAMPLE2) {
  Solution sol;
}