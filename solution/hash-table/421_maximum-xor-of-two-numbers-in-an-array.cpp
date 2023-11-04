/**
 * @author Anti
 * @date 2023/11/4
 * @see https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array
 */

#include <unordered_set>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int findMaximumXOR(std::vector<int>& nums) {
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      std::unordered_set<int> exist;
      ans = ans << 1 | 1;
      for (auto& num : nums) {
        exist.emplace(num >> i);
      }
      bool flag = std::any_of(exist.begin(), exist.end(),
                              [&ans, &exist](const int& num) {
                                return exist.count(ans ^ num) > 0;
                              });
      if (!flag) {
        ans ^= 1;
      }
    }
    return ans;
  }
};

TEST(test421, SAMPLE1) {
  Solution sol;
  std::vector nums{3, 10, 5, 25, 2, 8};
  int ans = 28;
  EXPECT_EQ(sol.findMaximumXOR(nums), ans);
}

TEST(test421, SAMPLE2) {
  Solution sol;
  std::vector nums{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
  int ans = 127;
  EXPECT_EQ(sol.findMaximumXOR(nums), ans);
}