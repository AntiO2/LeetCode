/**
 * @author Anti
 * @date 2023/11/2
 * @see https://leetcode.cn/problems/rings-and-rods
 */

#include <unordered_set>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int countPoints(std::string rings) {
    std::vector<std::unordered_set<char>> book(10);
    for (auto iter = rings.begin(); iter != rings.end();) {
      auto c = *iter++;
      book[*iter++ - '0'].emplace(c);
    }
    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
      if (book[i].size() == 3) {
        ++cnt;
      }
    }
    return cnt;
  }
};

TEST(test2103, SAMPLE1) {
  Solution sol;
  std::string ring("B0B6G0R6R0R6G9");
  auto ans = 1;
  EXPECT_EQ(sol.countPoints(ring), ans);
}

TEST(test2103, SAMPLE2) {
  Solution sol;
}