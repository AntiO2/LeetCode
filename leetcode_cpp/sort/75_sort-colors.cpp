/**
 * @author Anti
 * @date 2023/11/9
 * @see https://leetcode.cn/problems/sort-colors
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int p0 = 0, p1 = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        std::swap(nums[p1], nums[i]);
        ++p1;
      } else if (nums[i] == 0) {
        std::swap(nums[p0], nums[i]);
        if (p0 < p1) {
          std::swap(nums[i], nums[p1]);
        }
        ++p0;
        ++p1;
      }
    }
  }
};  // sort-colors

TEST(test75, SAMPLE1) {
  Solution sol;
}

TEST(test75, SAMPLE2) {
  Solution sol;
}