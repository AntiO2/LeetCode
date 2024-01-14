/**
 * @author Anti
 * @date 2024-01-13
 * @see https://leetcode.cn/problems/construct-string-with-repeat-limit
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <list>
using namespace std;
class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    std::vector<int> cnt(26,0);
    for(auto&c:s) {
      cnt[c-'a']++;
    }
    std::list<std::pair<char,int>> available;
    for(int i = 0; i < 26;i++) {
      if(cnt[i]) {
        available.emplace_front(std::pair{'a'+i, cnt[i]});
      }
    }
    auto l = s.length();
    std::stringstream ss;
    int prev_continue = 0;
    char prev = 0;
    while (!available.empty()) {
      if(prev==available.front().first) {
        if(prev_continue==repeatLimit) {
          if(available.size()==1) {
            break ;
          }
          auto iter = std::next(available.begin(),1);
          iter->first>>1;
          prev = iter->first;
          prev_continue = 1;
          iter->second--;
          if(iter->second==0) {
            available.erase(iter);
          }
          ss<<prev;
        } else {
          prev_continue++;
          available.begin()->second--;
          if (available.begin()->second == 0) {
            available.pop_front();
          }
          ss<<prev;
        }
      } else {
        prev_continue = 1;
        prev = available.begin()->first;
        available.begin()->second--;
        if (available.begin()->second == 0) {
          available.pop_front();
        }
        ss<<prev;
      }
    }
    std::string ans;
    ss>>ans;
    return ans;
  }
};  // construct-string-with-repeat-limit

TEST(test2182, SAMPLE1) {
  Solution sol;
  std::string word="cczazcc",ans="zzcccac";
  EXPECT_EQ(sol.repeatLimitedString(word,3),ans);
}

TEST(test2182, SAMPLE2) {
  Solution sol;
}