//
// Created by Anti on 2023/10/18.
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int tot_sum = 0;
    int ans = INT32_MIN;
    size_t l = nums.size();
    for (int i = 0; i < l; ++i) {
      tot_sum += nums[i];
      if (tot_sum > ans) {
        ans = tot_sum;
      }
      if (tot_sum < 0) {
        tot_sum = 0;
      }
    }
    return ans;
  }
};
class Solution2 {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int prevMin = 0;
    int totSum = 0;
    int ans = nums[0];  // 至少包含一个元素
    size_t l = nums.size();
    for (int i = 0; i < l; ++i) {
      totSum += nums[i];
      ans = std::max(ans, totSum - prevMin);
      prevMin = std::min(prevMin, totSum);
    }
    return ans;
  }
};

TEST(test53, SAMPLE1) {
  Solution sol;
  std::vector nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int ans = 6;
  EXPECT_EQ(sol.maxSubArray(nums), ans);
  // LOG_INFO("SAMPLE1 PASS");
}

TEST(test53, SAMPLE2) {
  Solution sol;
  std::vector nums{5, 4, -1, 7, 8};
  int ans = 23;
  EXPECT_EQ(sol.maxSubArray(nums), ans);
  // LOG_INFO("SAMPLE2 PASS");
}

TEST(test53, SAMPLE3) {
  Solution sol;
  std::vector nums{-2, 1};
  int ans = 1;
  EXPECT_EQ(sol.maxSubArray(nums), ans);
}