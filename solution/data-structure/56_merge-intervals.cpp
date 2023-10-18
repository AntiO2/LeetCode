//
// Created by Anti on 2023/10/18.
//
#include <algorithm>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> ans;
    std::ranges::sort(intervals,
                      [](const std::vector<int>& a, const std::vector<int>& b) {
                        return a.at(0) < b.at(0);
                      });
    bool exist = false;
    int tmp_left, tmp_right;
    for (const auto& interval : intervals) {
      if (exist) {
        if (tmp_right >= interval[0]) {
          //可以合并
          tmp_right = std::max(tmp_right, interval[1]);
        } else {
          ans.emplace_back(std::vector{tmp_left, tmp_right});
          tmp_left = interval[0];
          tmp_right = interval[1];
        }
      } else {
        tmp_left = interval[0];
        tmp_right = interval[1];
        exist = true;
      }
    }
    if (exist) {
      ans.emplace_back(std::vector{tmp_left, tmp_right});
    }
    return ans;
  }
};

TEST(test56, SAMPLE1) {
  Solution sol;
  std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  std::vector<std::vector<int>> ans = {{1, 6}, {8, 10}, {15, 18}};
  EXPECT_EQ(sol.merge(intervals), ans);
  // LOG_INFO("SAMPLE1 PASS");
}

TEST(test56, SAMPLE2) {
  Solution sol;
  // LOG_INFO("SAMPLE2 PASS");
}