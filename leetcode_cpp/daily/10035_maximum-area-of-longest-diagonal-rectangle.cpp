/**
 * @author Anti
 * @date 2024-01-08
 * @see https://leetcode.cn/problems/maximum-area-of-longest-diagonal-rectangle
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
    int max_len  = 0;
    int max_sum = 0;
    for(auto & v:dimensions) {
      auto w= v[0], h = v[1];
      auto len = w*w+h*h;
      auto sum = w*h;
      if(len ==max_len&&sum>max_sum ) {
        max_len = len;
        max_sum = sum;
      } else if(len>max_len) {
        max_len = len;
        max_sum = sum;
      }
    }
    return max_sum;
  }
};  // maximum-area-of-longest