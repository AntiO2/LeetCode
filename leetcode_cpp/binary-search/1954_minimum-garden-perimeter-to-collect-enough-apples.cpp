/**
 * @author Anti
 * @date 2023-12-24
 * @see
 * https://leetcode.cn/problems/minimum-garden-perimeter-to-collect-enough-apples
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
  const int max_n = 62996;
 public:
  long long minimumPerimeter(long long neededApples) {
    int l = 0, r = max_n;
    while(l < r) {
      auto mid = (l+r)>>1;
      if(get_sum(mid) >=neededApples) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    return l*8;
  }
  static inline long long get_sum(long long n) {
    return 2*n*(n+1)*(2*n+1);
  }
};  // minimum-garden-perimeter-to-collect-enough-apples

TEST(test1954, TEST_MAX) {
  const long long max = 1e15;
  Solution sol;
  long long n = 0;
  while(sol.get_sum(n) < max) {
    n++;
  }
  LOG_DEBUG("%lld",n);
}

TEST(test1954, SAMPLE2) {
  Solution sol;
  EXPECT_EQ(sol.minimumPerimeter(1),8);
  EXPECT_EQ(sol.minimumPerimeter(12),8);
  EXPECT_EQ(sol.minimumPerimeter(13),16);
  EXPECT_EQ(sol.minimumPerimeter(1000000000),5040);
}