/**
 * @author Anti
 * @date 2023/10/18
 * @see https://leetcode.cn/problems/maximal-score-after-applying-k-operations
 */

#include <cmath>
#include <queue>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  long long maxKelements(std::vector<int>& nums, int k) {
    std::priority_queue<int> pq;
    for (const auto& num : nums) {
      pq.emplace(num);
    }
    long long ans = 0;
    while (k--) {
      auto max = pq.top();
      ans += max;
      pq.pop();
      pq.emplace(std::ceil(double(max) / 3));
    }
    return ans;
  }
};

TEST(test2530, SAMPLE1) {
  Solution sol;
  std::vector nums{10, 10, 10, 10, 10};
  int k = 5;
  int ans = 50;
  EXPECT_EQ(sol.maxKelements(nums, k), ans);
}

TEST(test2530, SAMPLE2) {
  Solution sol;
  std::vector nums{1, 10, 3, 3, 3};
  int k = 3;
  int ans = 17;
  EXPECT_EQ(sol.maxKelements(nums, k), ans);
}