/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/jump-game-ii
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include "queue"
class Solution {
 public:
  int jump(std::vector<int>& nums) {
    int maxPos = 0, n = nums.size(), end = 0, step = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (maxPos >= i) {
        maxPos = std::max(maxPos, i + nums[i]);
        if (i == end) {
          end = maxPos;
          ++step;
        }
      }
    }
    return step;
  }
  int jump2(std::vector<int>& nums) {
    std::priority_queue<int> reachable;
    std::vector book(nums.size(), INT_MAX);
    book[0] = 0;
    reachable.emplace(0);
    while (!reachable.empty()) {
      auto curr = reachable.top();
      reachable.pop();
      for (auto i = std::min(nums[curr] + curr, int(nums.size()) - 1); i > curr;
           --i) {
        if (book[i] > book[curr] + 1) {
          book[i] = book[curr] + 1;
          reachable.emplace(i);
        } else {
          break;
        }
      }
    }
    return book[nums.size() - 1];
  }
};

TEST(test45, SAMPLE1) {
  Solution sol;
  std::vector nums{2, 3, 1, 1, 4};
  EXPECT_EQ(sol.jump(nums), 2);
}

TEST(test45, SAMPLE2) {
  Solution sol;
}