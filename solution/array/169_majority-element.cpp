/**
 * @author Anti
 * @date 2023/11/9
 * @see https://leetcode.cn/problems/majority-element
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int majorityElement(std::vector<int>& nums) {
    int vote = 0;
    int candidate = 0;
    for (auto num : nums) {
      if (!vote) {
        candidate = num;
      }
      if (candidate == num) {
        ++vote;
      } else {
        --vote;
      }
    }
    return candidate;
  }
};  // majority-element

TEST(test169, SAMPLE1) {
  Solution sol;
}

TEST(test169, SAMPLE2) {
  Solution sol;
}