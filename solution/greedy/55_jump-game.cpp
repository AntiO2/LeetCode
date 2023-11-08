/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/jump-game
 */

#include <queue>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  bool canJump(std::vector<int>& nums) {
    int max_dis = 0;
    int l = nums.size() - 1;
    for (int i = 0; i <= l && i <= max_dis; i++) {
      max_dis = std::max(max_dis, i + nums[i]);
    }
    return max_dis >= l;
  }
};
TEST(test55, SAMPLE1) {
  Solution sol;
  std::vector n{2, 3, 1, 1, 4};
  EXPECT_EQ(sol.canJump(n), true);
}

TEST(test55, SAMPLE2) {
  Solution sol;
}