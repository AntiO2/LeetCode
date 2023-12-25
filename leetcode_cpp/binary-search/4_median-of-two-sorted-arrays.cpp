/**
 * @author Anti
 * @date 2023/11/7
 * @see https://leetcode.cn/problems/median-of-two-sorted-arrays
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      // 保证nums1长度较小
      return findMedianSortedArrays(nums2, nums1);
    }
    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    // first_half_max：前一部分的最大值
    // last_half_min：后一部分的最小值
    int first_half_max = 0, last_half_min = 0;

    while (left <= right) {
      // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
      // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
      int i = (left + right) / 2;   // 第一个数组的分界线
      int j = (m + n + 1) / 2 - i;  // 第二个数组的分界线

      // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i],
      // nums2[j-1], nums2[j]
      int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);  // 边界条件
      int nums_i = (i == m ? INT_MAX : nums1[i]);
      int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
      int nums_j = (j == n ? INT_MAX : nums2[j]);

      if (nums_im1 <= nums_j) {
        // 满足条件。
        // 尝试将边界往前调整
        first_half_max = std::max(nums_im1, nums_jm1);
        last_half_min = std::min(nums_i, nums_j);
        left = i + 1;
      } else {
        // 不满足条件，将边界往后调整
        right = i - 1;
      }
    }

    return (m + n) % 2 == 0 ? (first_half_max + last_half_min) / 2.0
                            : first_half_max;
  }
};
TEST(test4, SAMPLE1) {
  Solution sol;
}

TEST(test4, SAMPLE2) {
  Solution sol;
}