/**
 * @author Anti
 * @date 2024-01-14
 * @see
 * https://leetcode.cn/problems/find-beautiful-indices-in-the-given-array-ii
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  std::vector<int> prefix_function( std::string s) {
    int n = (int)s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
      int j = pi[i - 1];
      while (j > 0 && s[i] != s[j]) j = pi[j - 1];
      if (s[i] == s[j]) j++;
      pi[i] = j;
    }
    return pi;
  }
  std::vector<int> find_occurrences(std::string s,std::string a) {
    std::string cur = a + '#' + s;
    int sz1 = s.size(), sz2 = a.size();
    std::vector<int> v;
    std::vector<int> lps = prefix_function(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
      if (lps[i] == sz2) v.push_back(i - 2 * sz2);
    }
    return v;
  }
 public:
  std::vector<int> beautifulIndices(std::string s, std::string a, std::string b, int k) {
    std::vector<int> ans,match_a,match_b;
    auto ls = s.length(),la = a.length(), lb = b.length();
    match_a = find_occurrences(s,a);
    match_b = find_occurrences(s,b);

    auto iter_b = match_b.begin();
    for(auto&a_index : match_a) {
      while(iter_b!=match_b.end()&&a_index-*iter_b>k) {
        iter_b++;
      }
      if(iter_b!=match_b.end()&&std::abs(a_index-*iter_b)<=k) {
        ans.emplace_back(a_index);
      }
    }
    return ans;
  }
}; // find-beautiful-indices-in-the-given-array-i

TEST(test100207, SAMPLE1) {
  Solution sol;
  std::string s(5*1e5,'a'),a(1e5,'a'),b(1e5,'a');
  LOG_INFO("%d",sol.beautifulIndices(s,a,b,100).size());
}

TEST(test100207, SAMPLE2) {
  Solution sol;
}