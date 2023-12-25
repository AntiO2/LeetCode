/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/kth-largest-element-in-an-array
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  int select_kth_big(std::vector<int>& nums, int left, int right, int k) {
    if (left == right) {
      return nums[k];
    }
    int partition = nums[left], left_bound = left, right_bound = right;
    while (left_bound < right_bound) {
      while (nums[right_bound] <= partition && left_bound < right_bound) {
        right_bound--;
      }
      // right bound右侧的全都小于partion
      nums[left_bound] = nums[right_bound];
      while (nums[left_bound] > partition && left_bound < right_bound) {
        left_bound++;
      }
      nums[right_bound] = nums[left_bound];
      // left bound左侧的全都大于partition
    }
    nums[left_bound] = partition;
    // assert(left_bound <= right_bound);
    if (k == left_bound) {
      return nums[k];
    }
    if (k < left_bound) {
      // 如果k在当前分割点的前面
      return select_kth_big(nums, left, left_bound - 1, k);
    } else {
      return select_kth_big(nums, right_bound + 1, right, k);
    }
  }

 public:
  int findKthLargest(std::vector<int>& nums, int k) {

    std::partial_sort(nums.begin(), nums.begin() + k, nums.end(),
                      std::greater<>{});
    return nums[k - 1];
    // return select_kth_big(nums, 0, nums.size() - 1, k - 1);
  }
};

TEST(test215, SAMPLE1) {
  Solution sol;
  std::vector nums{3, 2, 1, 5, 6, 4};
  EXPECT_EQ(sol.findKthLargest(nums, 2), 5);
}

TEST(test215, SAMPLE2) {
  Solution sol;
  std::vector nums{7, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ(sol.findKthLargest(nums, 5), 3);
}
TEST(test215, SAMPLE3) {
  Solution sol;
  std::vector nums{3, 2, 1, 5, 6, 4};
  EXPECT_EQ(sol.findKthLargest(nums, 2), 5);
}

TEST(test215, SAMPLE4) {
  Solution sol;
  std::vector nums{3, 1, 2, 4};
  EXPECT_EQ(sol.findKthLargest(nums, 2), 3);
}