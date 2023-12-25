/**
 * @author Anti
 * @date 2023-11-26
 * @see
 * https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int uniqueLetterString(std::string s) {
    int n = s.size();
    std::vector<int> mp[26];
    for(int i = 0; i < n; i++) {
      int j = s[i] - 'A';
      if(mp[j].empty()) {
        mp[j].push_back(-1);
      }
      mp[j].push_back(i);
    }
    long long ans = 0;
    for(int j = 0; j < 26; j++) {
      auto& v = mp[j];
      v.push_back(n);
      int m = v.size();
      for(int i = 1; i < m - 1; i++) {
        ans += (long long)(v[i] - v[i - 1])*(v[i + 1] - v[i]);
      }
    }
    return ans;
  }
}; // count-unique-characters-of-all-substrings-of-a-given-string

TEST(test828, SAMPLE1) {
  Solution sol;
}

TEST(test828, SAMPLE2) {
  Solution sol;
}