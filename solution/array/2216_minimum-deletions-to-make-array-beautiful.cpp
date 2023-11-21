/**
 * @author Anti
 * @date 2023-11-21
 * @see https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int minDeletion(std::vector<int>& nums) {
    if(nums.empty()) {
      return 0;
    }
    bool even = true; // 标记当前的奇数还是偶数下标
    int i = 0;
    auto deleted = 0;
    while(i +1< nums.size()) {
      if(nums[i]==nums[i+1]&&even) {
        ++i;
        ++deleted;
      } else {
        ++i;
        even = !even;
      }
    }
    if ((nums.size() - deleted) % 2 != 0) {
      ++deleted;
    }
    return deleted;

  }
}; // minimum-deletions-to-make-array-beautiful

TEST(test2216, SAMPLE1) {
  Solution sol;
  std::vector nums{1,1,2,3,5};
  EXPECT_EQ(sol.minDeletion(nums),1);
}

TEST(test2216, SAMPLE2) {
  Solution sol;
}