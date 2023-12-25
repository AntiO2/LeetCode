/**
 * @author Anti
 * @date 2023-12-02
 * @see https://leetcode.cn/problems/car-pooling
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
    std::vector<int> diff(1001,0);
    for(auto trip:trips) {
      diff[trip[1]]+=trip[0];
      diff[trip[2]]-=trip[0];
    }
    auto now = 0;
    for(int i = 0 ; i <=1000;i++) {
      now+=diff[i];
      if(now > capacity) {
        return false;
      }
    }
    return true;
  }
}; // car-pooling

TEST(test1094, SAMPLE1) {
  Solution sol;
}

TEST(test1094, SAMPLE2) {
  Solution sol;
}