/**
 * @author Anti
 * @date 2023/10/29
 * @see https://leetcode.cn/problems/h-index
 */
#include <algorithm>
#include <list>
#include <ranges>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int hIndex(std::vector<int>& citations) {
    std::ranges::sort(citations, std::greater<>{});
    int i = 0;
    for (i = 0; i < citations.size(); i++) {
      if (citations[i] < i + 1) {
        break;
      }
    }
    return i;
  }
};

TEST(test274, SAMPLE1) {
  Solution sol;
  std::vector c{3, 0, 6, 1, 5};
  int h = 3;
  EXPECT_EQ(sol.hIndex(c), h);
}

TEST(test274, SAMPLE2) {
  Solution sol;
  std::vector c{1, 3, 1};
  int h = 1;
  EXPECT_EQ(sol.hIndex(c), h);
}

TEST(test274, SAMPLE3) {
  Solution sol;
  std::vector c{0, 0, 0};
  int h = 1;
  EXPECT_EQ(sol.hIndex(c), h);
}