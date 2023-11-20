/**
 * @author Anti
 * @date 2023-11-19
 * @see https://leetcode.cn/problems/separate-black-and-white-balls
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  long long minimumSteps(std::string s) {
    long long ans = 0;
    int pos = 0;
    auto s_len = s.size();
    for(int i = 0; i < s_len;i++) {
      if(s[i]=='0') {
        ans += i - pos;
        ++pos;
      }
    }
    return ans;
  }
};  // separate-black-and-white-balls

TEST(test100122, SAMPLE1) {
  Solution sol;
}

TEST(test100122, SAMPLE2) {
  Solution sol;
}