/**
 * @author Anti
 * @date 2023/11/9
 * @see https://leetcode.cn/problems/find-the-duplicate-number
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int findDuplicate(std::vector<int>& nums) {
    int n = nums.size(), ans = 0;

    int bit_max = 31;
    while (!((n - 1) >> bit_max)) {
      bit_max -= 1;
    }
    // 确定最高位为bit_max
    for (int bit = 0; bit <= bit_max; ++bit) {
      int x = 0, y = 0;
      for (int i = 0; i < n; ++i) {
        if (nums[i] & (1 << bit)) {
          x += 1;
        }
        if (i >= 1 && (i & (1 << bit))) {
          y += 1;
        }
      }
      if (x > y) {
        ans |= 1 << bit;
      }
    }
    return ans;
  }
};  // find-the-duplicate-number

TEST(test287, SAMPLE1) {
  Solution sol;
}

TEST(test287, SAMPLE2) {
  Solution sol;
}