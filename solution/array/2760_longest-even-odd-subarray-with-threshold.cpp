/**
 * @author Anti
 * @date 2023/11/16
 * @see https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
 public:
  int longestAlternatingSubarray(std::vector<int>& nums, int threshold) {
    int n = nums.size();
    int ans = 0;
    int curr = 0;
    bool odd = true;  // 上一个数是否为奇数. 默认以偶数开头
    for (int i = 0; i < n; i++) {
      if (nums[i] > threshold) {
        ans = std::max(ans, curr);
        odd = true;
        curr = 0;
        continue;
      }
      if (nums[i] % 2 && !odd) {
        odd = true;
        ++curr;
        continue;
      }
      if (nums[i] % 2 == 0 && odd) {
        odd = false;
        ++curr;
        continue;
      }
      // 不满足子数组条件
      ans = std::max(ans, curr);
      if (nums[i] % 2 == 0) {
        curr = 1;
        odd = false;
      } else {
        curr = 0;
        odd = true;
      }
    }
    ans = std::max(ans, curr);
    return ans;
  }
};  // longest-even-odd-subarray-with-threshold

TEST(test2760, SAMPLE1) {
  Solution sol;
  std::vector nums{3, 2, 5, 4};
  int threshold = 5;
  EXPECT_EQ(sol.longestAlternatingSubarray(nums, threshold), 3);
}

TEST(test2760, SAMPLE2) {
  Solution sol;
}