/**
 * @author Anti
 * @date 2023/11/9
 * @see https://leetcode.cn/problems/next-permutation
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      // 找到第一个升序。
      i--;
    }
    if (i >= 0) {
      int j = nums.size() - 1;
      while (nums[j] <= nums[i]) {
        --j;
      }
      std::swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};  // next-permutation

TEST(test31, SAMPLE1) {
  Solution sol;
}

TEST(test31, SAMPLE2) {
  Solution sol;
}