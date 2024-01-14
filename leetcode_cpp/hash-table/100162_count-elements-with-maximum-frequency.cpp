/**
 * @author Anti
 * @date 2024-01-14
 * @see https://leetcode.cn/problems/count-elements-with-maximum-frequency
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int maxFrequencyElements(std::vector<int>& nums) {
    std::unordered_map<int,int> cnt;
    for(auto&num:nums) {
      cnt[num]++;
    }
    auto max = 0,ans = 0;
    for(auto&[num,c]:cnt) {
      if(c>max) {
        max  = c;
        ans  = c;
      } else if(max==c) {
        ans +=c;
      }
    }
    return ans;
  }
}; // count-elements-with-maximum-frequency

TEST(test100162, SAMPLE1) {
  Solution sol;
}

TEST(test100162, SAMPLE2) {
  Solution sol;
}