/**
 * @author Anti
 * @date 2023/11/7
 * @see https://leetcode.cn/problems/search-insert-position
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int searchInsert(std::vector<int>& nums, int target) {
    size_t l = 0, r = nums.size();
    while (l < r) {
      auto mid = (l + r) / 2;
      if (nums[mid] == target) {
        return static_cast<int>(mid);
      }
      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return static_cast<int>(l);
  }
};

TEST(test35, SAMPLE1) {
  Solution sol;
  std::vector nums{1, 3, 5, 6};
  int target = 7;
  EXPECT_EQ(sol.searchInsert(nums, target), 4);
}

TEST(test35, SAMPLE2) {
  Solution sol;
  std::vector nums{1, 3, 5, 6};
  int target = 5;
  EXPECT_EQ(sol.searchInsert(nums, target), 2);
}

TEST(test35, SAMPLE3) {
  Solution sol;
  std::vector nums{1, 3, 5, 6};
  int target = 0;
  EXPECT_EQ(sol.searchInsert(nums, target), 0);
}