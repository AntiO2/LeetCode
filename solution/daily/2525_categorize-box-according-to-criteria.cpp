/**
 * @author Anti
 * @date 2023/10/20
 * @see https://leetcode.cn/problems/categorize-box-according-to-criteria
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
/*
 * 如果满足以下条件，那么箱子是 "Bulky" 的：
箱子 至少有一个 维度大于等于 104 。
或者箱子的 体积 大于等于 109 。
如果箱子的质量大于等于 100 ，那么箱子是 "Heavy" 的。
如果箱子同时是 "Bulky" 和 "Heavy" ，那么返回类别为 "Both" 。
如果箱子既不是 "Bulky" ，也不是 "Heavy" ，那么返回类别为 "Neither" 。
如果箱子是 "Bulky" 但不是 "Heavy" ，那么返回类别为 "Bulky" 。
如果箱子是 "Heavy" 但不是 "Bulky" ，那么返回类别为 "Heavy" 。
 */
class Solution {
 public:
  std::string categorizeBox(int length, int width, int height, int mass) {
    unsigned long long l = length;
    unsigned long long w = width;
    unsigned long long h = height;
    bool is_bulky =
        length >= 1e4 || width >= 1e4 || height >= 1e4 || l * w * h >= 1e9;
    if (mass >= 100) {
      if (is_bulky) {
        return "Both";
      } else {
        return "Heavy";
      }
    } else {
      if (is_bulky) {
        return "Bulky";
      } else {
        return "Neither";
      }
    }
  }
};

TEST(test2525, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.categorizeBox(1000, 35, 700, 300), "Heavy");
}

TEST(test2525, SAMPLE2) {
  Solution sol;
  EXPECT_EQ(sol.categorizeBox(200, 50, 800, 50), "Neither");
}