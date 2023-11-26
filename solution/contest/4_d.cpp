/**
 * @author Anti
 * @date 2023-11-26
 * @see https://leetcode.cn/problems/d
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
  long long beautifulSubstrings(std::string s, int k) {
    int mi = 1;
    while(mi*mi%k!=0) {++mi;}
    auto l = s.length();
    k = mi*2;
    std::vector<int> prev_vowels(l + 1,0);
    std::vector<int> prev_consonants(l + 1,0);
    std::map<int,std::vector<int>> map;
    map[0].emplace_back(0);
    int prev_vo = 0, prev_con = 0;
    int cnt = 0;
    for(int i = 1 ;i <= l;i++) {
      if(check( s[i-1] )) {
        ++prev_vo;
        ++cnt;
      } else {
        ++prev_con;
        --cnt;
      }
      prev_vowels[i] = prev_vo;
      prev_consonants[i] = prev_con;
      map[cnt].emplace_back(i);
    }
    long long ans = 0;
    for(auto&[cnt,tmp]:map) {
      std::unordered_map<int,int> cnt_k;
      for(auto t:tmp) {
        cnt_k[t%k] ++;
      }
      for(auto it:cnt_k) {
        ans+=it.second*(it.second-1)/2;
      }
    }
    return ans;
  }
};// d

TEST(test4, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.beautifulSubstrings("baeyh",2),2);
}

TEST(test4, SAMPLE2) {
  Solution sol;
}