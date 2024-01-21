/**
 * @author Anti
 * @date 2024-01-20
 * @see
 * https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int minimumCost(std::vector<int>& nums) {
        int ans = nums[0];
        std::sort(std::next(nums.begin()),nums.end());
        ans = ans+nums[1]+nums[2];
        return ans;
  }
};  // divide-an-array-into-subarrays-with-minimum-cost-i

TEST(test100181, SAMPLE1) {
  Solution sol;
}

TEST(test100181, SAMPLE2) {
  Solution sol;
}