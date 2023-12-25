/**
 * @author Anti
 * @date 2023/11/7
 * @see https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int findMin(std::vector<int>& nums) {
    int l = 0;
    int r = nums.size();
    int ans = nums[0];
    while (l < r) {
      auto mid = (l + r) >> 1;
      if (nums[0] > nums[mid]) {
        // nums[0]~mid 中有严格旋转点。
        r = mid;
      } else {
        // mid > nums[0] 在右侧可能是升序。也可能是升序，然后从最小开始。
        l = mid + 1;
      }
    }
    if (l != nums.size()) {
      ans = std::min(ans, nums[l]);
    }
    return ans;
  }
};

TEST(test153, SAMPLE1) {
  Solution sol;
  LOG_INFO("1");
  std::vector n{3, 4, 5, 1, 2};
  EXPECT_EQ(sol.findMin(n), 1);
}

TEST(test153, SAMPLE2) {
  Solution sol;
}