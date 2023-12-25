/**
 * @author Anti
 * @date 2023-12-23
 * @see https://leetcode.cn/problems/remove-stones-to-minimize-the-total
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <queue>
class Solution {
 public:
  int minStoneSum(std::vector<int>& piles, int k) {
    std::priority_queue<int> max_heap(piles.begin(),piles.end());
    int ans = 0;
    while(k--) {
      auto max =  max_heap.top();
      max_heap.pop();
      max_heap.emplace(max-max/2);
    }
    while (!max_heap.empty()) {
      ans+=max_heap.top();
      max_heap.pop();
    }
    return ans;
  }
}; // remove-stones-to-minimize-the-total

TEST(test1962, SAMPLE1) {
  Solution sol;
  std::vector nums{5,4,9};
  EXPECT_EQ(sol.minStoneSum(nums,2), 12);
}

TEST(test1962, SAMPLE2) {
  Solution sol;
}