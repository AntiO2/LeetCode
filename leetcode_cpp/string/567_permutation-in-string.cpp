/**
 * @author Anti
 * @date 2023-12-07
 * @see https://leetcode.cn/problems/permutation-in-string
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  bool checkInclusion(std::string s1, std::string s2) {
    if(s1.length()>s2.length()) {
      return false;
    }
    std::vector<int> cnt1(26,0);
    for(auto c:s1) {
      cnt1[c-'a']++;
    }
    auto l1 = s1.length(), l2= s2.length();
    std::vector<int> cnt2(26,0);
    int i = 0;
    for(; i < l1; i++) {
      cnt2[s2[i]-'a']++;
    }
    int l = 0;
    int diff = 0;
    for(int k = 0; k < 26; k++) {
      if(cnt1[k]!=cnt2[k]) {
        diff++;
      }
    }
    auto &s = s2;
    while(i < l2) {
      if(diff==0) {
        return true;
      }
      if(cnt2[s[l]-'a']==cnt1[s[l]-'a']) {
        diff++;
      }
      --cnt2[s[l]-'a'];
      if(cnt2[s[l]-'a']==cnt1[s[l]-'a']) {
        diff--;
      }
      if(cnt2[s[i]-'a']==cnt1[s[i]-'a']) {
        diff++;
      }
      ++cnt2[s[i]-'a'];
      if(cnt2[s[i]-'a']==cnt1[s[i]-'a']) {
        diff--;
      }
      ++i;
      ++l;
    }
    return diff == 0;
  }
};  // permutation-in-string

TEST(test567, SAMPLE1) {
  Solution sol;
}

TEST(test567, SAMPLE2) {
  Solution sol;
}