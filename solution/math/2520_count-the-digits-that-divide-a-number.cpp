/**
 * @author Anti
 * @date 2023/10/26
 * @see https://leetcode.cn/problems/count-the-digits-that-divide-a-number
 */

#include <algorithm>
#include <numeric>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int countDigits(int num) {
    int ans = 0;
    const int x = num;
    while (num) {
      if (x % (num % 10) == 0) {
        ++ans;
      }
      num /= 10;
    }
    return ans;
  }
};

TEST(test2520, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.countDigits(1248), 4);
}

TEST(test2520, SAMPLE2) {
  Solution sol;
  EXPECT_EQ(sol.countDigits(121), 2);
}
TEST(test2520, SAMPLE3) {
  Solution sol;
  EXPECT_EQ(sol.countDigits(7), 1);
}