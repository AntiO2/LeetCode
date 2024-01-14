/**
 * @author Anti
 * @date 2024-01-14
 * @see https://leetcode.cn/problems/find-beautiful-indices-in-the-given-array-i
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<int> beautifulIndices(std::string s, std::string a, std::string b, int k) {
    std::vector<int> ans,match_a,match_b;
    auto ls = s.length(),la = a.length(), lb = b.length();
    for(int i = 0;i<ls;i++) {

      if(i + la <= ls) {
        if(s.substr(i,la).compare(a)==0) {
          match_a.emplace_back(i);
        }
      }
      if(i + lb <= ls) {
        if(s.substr(i,lb).compare(b)==0) {
          match_b.emplace_back(i);
        }
      }
    }

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

TEST(test100165, SAMPLE1) {
  Solution sol;
  std::vector ans{16,33};
  EXPECT_EQ(sol.beautifulIndices("isawsquirrelnearmysquirrelhouseohmy","my","squirrel",15),ans);
}

TEST(test100165, SAMPLE2) {
  Solution sol;
}