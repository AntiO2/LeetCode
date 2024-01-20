/**
 * @author Anti
 * @date 2024-01-17
 * @see https://leetcode.cn/problems/find-maximum-number-of-string-pairs
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int maximumNumberOfStringPairs(std::vector<std::string>& words) {
        std::map<std::string,std::vector<int>> map;
        for(int i = 0; i < words.size();i++) {
          map[words[i]].emplace_back(i);
        }
        int ans = 0;
        for(int i = 0; i < words.size();i++) {
          std::reverse(words[i].begin(), words[i].end());
          auto iter = map.find(words[i]);
          if(iter==map.end()) {
            continue ;
          }
          auto &v = (*iter).second;
          for(auto j:v) {
            if(j>i) {
              ans++;
            }
          }
        }
        return ans;
  }
}; // find-maximum-number-of-string-pairs

TEST(test2744, SAMPLE1) {
  Solution sol;
}

TEST(test2744, SAMPLE2) {
  Solution sol;
}