//
// Created by Anti on 2023/10/17.
//

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int sumOfMultiples(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
        ans += i;
      }
    }
    return ans;
  }
};
TEST(test0, SAMPLE1) {
  Solution s;
  int n = 7;
  int ans = 21;
  EXPECT_EQ(s.sumOfMultiples(n), ans);
  // LOG_INFO("SAMPLE1 PASS");
}

TEST(test0, SAMPLE2) {
  Solution s;
  int n = 10;
  int ans = 40;
  EXPECT_EQ(s.sumOfMultiples(n), ans);
  // LOG_INFO("SAMPLE2 PASS");
}
