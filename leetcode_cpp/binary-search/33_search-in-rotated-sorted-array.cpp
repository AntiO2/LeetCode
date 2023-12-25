/**
 * @author Anti
 * @date 2023/11/7
 * @see https://leetcode.cn/problems/search-in-rotated-sorted-array
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    auto first = nums.begin();
    int len = nums.size() - 1;
    while (len > 0) {

      auto half = len >> 1;
      auto mid = first;
      LOG_DEBUG("%d %d %d", *first, half, len);
      std::advance(mid, half);
      if (*mid == target) {
        return static_cast<int>(std::distance(nums.begin(), mid));
      }
      if (nums[0] <= *mid) {
        // 左侧是有序的。
        if (nums[0] <= target && target < *mid) {
          // target在左侧有序部分
          len = half - 1;
        } else {
          first = mid + 1;
          len = len - half - 1;
        }
      } else {
        // 旋转点在mid左侧，右侧是有序的
        if (*mid < target && target < nums[0]) {
          // target在右侧
          first = mid + 1;
          len = len - half - 1;
        } else {
          len = half - 1;
        }
      }
      // 4 5 6 1 2 3
    }
    if (*first != target) {
      return -1;
    }
    return static_cast<int>(std::distance(nums.begin(), first));
  }
};

TEST(test33, SAMPLE1) {
  Solution sol;
  std::vector nums{4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(sol.search(nums, 0), 4);
}

TEST(test33, SAMPLE2) {
  Solution sol;
  std::vector nums{4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(sol.search(nums, 3), -1);
}

TEST(test33, SAMPLE3) {
  Solution sol;
  std::vector nums{1, 3, 5};
  EXPECT_EQ(sol.search(nums, 3), 1);
}
TEST(test33, SAMPLE4) {
  Solution sol;
  std::vector nums{9, 0, 2, 7, 8};
  EXPECT_EQ(sol.search(nums, 3), -1);
}