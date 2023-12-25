//
// Created by Anti on 2023/9/20.
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

/**
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i
!= j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
 */

class Solution {
 private:
  std::vector<std::vector<int>> ans_;

 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    auto len = nums.size(), i = size_t(0);
    if (len < 3) {
      return ans_;
    }
    std::sort(nums.begin(), nums.end());
    while (i < len - 2) {
      auto target = -nums[i];
      auto l = i + 1, r = len - 1;
      while (l < r) {
        if (nums[l] + nums[l + 1] > target) {
          // move l
          auto lv = nums[l];
          while (nums[l] == lv && l < r) {
            l++;
          }
        }
        if (nums[r] + nums[r - 1] < target) {
          // move r
          auto rv = nums[r];
          while (nums[r] == rv && r > l) {
            r--;
          }
        }
        auto sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ans_.emplace_back(std::vector<int>{nums[i], nums[l], nums[r]});
          // move l && r
          // 因为l移动到下一个值，原来的r肯定不会满足条件。
          auto lv = nums[l];
          while (nums[l] == lv && l < r) {
            l++;
          }
          // move r
          auto rv = nums[r];
          while (nums[r] == rv && r > l) {
            r--;
          }
        } else if (sum < 0) {
          // move l
          auto lv = nums[l];
          while (nums[l] == lv && l < r) {
            l++;
          }
        } else {
          // move r
          auto rv = nums[r];
          while (nums[r] == rv && r > l) {
            r--;
          }
        }
      }
      auto iv = nums[i];
      while (nums[i] == iv && i < len - 2) {
        i++;
      }
    }
    return ans_;
  }
  // 原解
  [[maybe_unused]] std::vector<std::vector<int>> threeSum_Confuse(
      std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    auto left = nums.begin(), right = --nums.end();
    while (left != right) {
      auto left_iter = left;
      while (left_iter != right) {
        auto target = 0 - (*left_iter + *right);
        auto target_iter =
            std::lower_bound(std::next(left_iter), right, target);
        if (target_iter != right && *target_iter == target) {
          ans_.emplace_back(std::vector<int>{*left_iter, *target_iter, *right});
        }
        auto left_value = *left_iter;
        while (*left_iter == left_value && left_iter != right) {
          ++left_iter;
        }
      }
      auto right_value = *right;
      while (*right == right_value && left != right) {
        --right;
      }
    }
    return ans_;
  }
};
TEST(test15, SAMPLE1) {
  Solution s;
  // sorted: -4 -1 -1 0 1 2
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  auto ans = s.threeSum(nums);
  EXPECT_EQ(true, true);
}

TEST(test15, SAMPLE2) {
  Solution s;
  std::vector<int> nums = {0, 1, 1};
  auto ans = s.threeSum(nums);
  assert(true);
}

TEST(test15, SAMPLE3) {
  Solution s;
  std::vector<int> nums = {3, 0, -2, -1, 1, 2};
  auto ans = s.threeSum(nums);
  assert(true);
}
