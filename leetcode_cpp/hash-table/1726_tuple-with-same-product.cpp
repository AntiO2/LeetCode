/**
 * @author Anti
 * @date 2023/10/19
 * @see https://leetcode.cn/problems/tuple-with-same-product
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int tupleSameProduct(std::vector<int>& nums) {
    std::unordered_map<int, int> count_times;
    int l = int(nums.size());
    for (int i = 0; i < l; i++) {
      for (int j = i + 1; j < l; j++) {
        count_times[nums[i] * nums[j]]++;
      }
    }
    int ans = 0;
    for (auto& count : count_times) {
      if (count.second > 1) {
        ans += count.second * (count.second - 1);
      }
    }
    return ans * 4;
  }
};

TEST(test1726, SAMPLE1) {
  Solution sol;
  std::vector nums{2, 3, 4, 6};
  // 6 8 12 12 18 24
  // (n)* (n-1) * 2 * 2 * 2
  EXPECT_EQ(sol.tupleSameProduct(nums), 8);
}

TEST(test1726, SAMPLE2) {
  Solution sol;
  std::vector nums{1, 2, 4, 5, 10};
  EXPECT_EQ(sol.tupleSameProduct(nums), 16);
}