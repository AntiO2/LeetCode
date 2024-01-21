/**
 * @author Anti
 * @date 2024-01-20
 * @see https://leetcode.cn/problems/find-if-array-can-be-sorted
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  bool canSortArray(std::vector<int>& nums) {
    auto now = std::popcount(uint32_t(nums[0]));
    auto left = nums.begin();
    auto iter = std::next(nums.begin());
    while(iter!=nums.end()) {
      auto curr = std::popcount(uint32_t(*iter));
      if(curr!=now) {
        std::sort(left, iter);
        left = iter;
        now = curr;
      }
      iter++;
    }
    std::sort(left,iter);
    for(int i = 1; i< nums.size();i++) {
      if(nums[i] < nums[i-1]) {
        return false;
      }
    }
    return true;
  }
};  // find-if-array-can-be-sorted

TEST(test100199, SAMPLE1) {
  Solution sol;
}

TEST(test100199, SAMPLE2) {
  Solution sol;
}