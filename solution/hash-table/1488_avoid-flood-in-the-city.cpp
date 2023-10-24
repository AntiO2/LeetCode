//
// Created by Anti on 2023/10/13.
//
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
 public:
  std::vector<int> avoidFlood(std::vector<int>& rains) {
    std::unordered_map<int, int> rainy_day;
    std::set<int> free_day;
    int day_num = int(rains.size());
    bool success = true;
    std::vector ans(day_num, 1);

    for (int i = 0; i < day_num; ++i) {
      auto r = rains[i];
      if (r) {
        ans[i] = -1;
        auto iter = rainy_day.find(r);
        if (iter != rainy_day.end()) {
          auto prev_day = iter->second;
          auto lower = free_day.lower_bound(prev_day);
          if (lower == free_day.end()) {
            success = false;
            break;
          }
          ans[*lower] = r;
          free_day.erase(lower);
        }
        rainy_day[r] = i;
      } else {
        free_day.emplace(i);
      }
    };
    return success ? ans : std::vector<int>();
  }
};

TEST(test1488, SAMPLE1) {
  Solution s;
  std::vector rains{1, 2, 3, 4};
  std::vector ans{-1, -1, -1, -1};

  EXPECT_EQ(s.avoidFlood(rains), ans);
  LOG_INFO("SAMPLE1 PASS");
}

TEST(test1488, SAMPLE2) {
  Solution s;
  std::vector rains{1, 2, 0, 0, 2, 1};
  std::vector ans{-1, -1, 2, 1, -1, -1};
  EXPECT_EQ(s.avoidFlood(rains), ans);
  LOG_INFO("SAMPLE2 PASS");
}

TEST(test1488, SAMPLE3) {
  Solution s;
  std::vector rains{1, 2, 0, 1, 2};
  std::vector<int> ans{};
  EXPECT_EQ(s.avoidFlood(rains), ans);
  LOG_INFO("SAMPLE3 PASS");
}
TEST(test1488, SAMPLE4) {
  Solution s;
  std::vector rains{0, 1, 1};
  std::vector<int> ans{};
  EXPECT_EQ(s.avoidFlood(rains), ans);
  LOG_INFO("SAMPLE4 PASS");
}
TEST(test1488, SAMPLE5) {
  Solution s;
  std::vector rains{1, 1, 0, 0};
  std::vector<int> ans{};
  EXPECT_EQ(s.avoidFlood(rains), ans);
}
TEST(test1488, SAMPLE6) {
  Solution s;
  std::vector rains{
      0,     72328, 0,     0,     94598, 54189, 39171, 53361, 0,     0,
      0,     72742, 0,     98613, 16696, 0,     32756, 23537, 0,     94598,
      0,     0,     0,     11594, 27703, 0,     0,     0,     20081, 0,
      24645, 0,     0,     0,     0,     0,     0,     0,     2711,  98613,
      0,     0,     0,     0,     0,     91987, 0,     0,     0,     22762,
      23537, 0,     0,     0,     0,     54189, 0,     0,     87770, 0,
      0,     0,     0,     27703, 0,     0,     0,     0,     20081, 16696,
      0,     0,     0,     0,     0,     0,     0,     35903, 0,     72742,
      0,     0,     0,     35903, 0,     0,     91987, 76728, 0,     0,
      0,     0,     2711,  0,     0,     11594, 0,     0,     22762, 24645,
      0,     0,     0,     0,     0,     53361, 0,     87770, 0,     0,
      39171, 0,     24577, 0,     0,     0,     24577, 0,     0,     72328,
      0,     0,     32756, 0,     0,     76728};
  std::vector<int> ans{
      1,     -1,    72328, 1,     -1,    -1, -1, -1,    94598, 54189, 53361,
      -1,    72742, -1,    -1,    98613, -1, -1, 23537, -1,    16696, 39171,
      32756, -1,    -1,    27703, 11594, 1,  -1, 20081, -1,    24645, 1,
      1,     1,     1,     1,     1,     -1, -1, 2711,  1,     1,     1,
      1,     -1,    91987, 1,     1,     -1, -1, 22762, 1,     1,     1,
      -1,    1,     1,     -1,    87770, 1,  1,  1,     -1,    1,     1,
      1,     1,     -1,    -1,    1,     1,  1,  1,     1,     1,     1,
      -1,    35903, -1,    1,     1,     1,  -1, 1,     1,     -1,    -1,
      76728, 1,     1,     1,     -1,    1,  1,  -1,    1,     1,     -1,
      -1,    1,     1,     1,     1,     1,  -1, 1,     -1,    1,     1,
      -1,    1,     -1,    24577, 1,     1,  -1, 1,     1,     -1,    1,
      1,     -1,    1,     1,     -1};
  EXPECT_EQ(s.avoidFlood(rains), ans);
}
TEST(test1488, SAMPLE7) {
  Solution s;
  std::vector rains{1, 0, 2, 3, 0, 1, 2};
  std::vector<int> ans{-1, 1, -1, -1, 2, -1, -1};
  EXPECT_EQ(s.avoidFlood(rains), ans);
}
TEST(test1488, SAMPLE8) {
  Solution s;
  std::vector rains{1, 0, 2, 0, 3, 0, 2, 0, 0, 0, 1, 2, 3};
  std::vector<int> ans{-1, 1, -1, 2, -1, 3, -1, 2, 1, 1, -1, -1, -1};
  EXPECT_EQ(s.avoidFlood(rains), ans);
}
TEST(test1488, SAMPLE9) {
  Solution s;
  std::vector rains{0,     0,     0, 0,     0, 0,     0,     0,
                    0,     0,     0, 0,     0, 56438, 0,     0,
                    76913, 0,     0, 53492, 0, 50824, 0,     0,
                    0,     0,     0, 0,     0, 0,     79212, 0,
                    0,     0,     0, 0,     0, 36713, 62045, 79212,
                    36713, 56438, 0, 0,     0, 62045, 0,     76913,
                    50824, 0,     0, 0,     0, 0,     53492, 0};
  std::vector<int> ans{};
  EXPECT_EQ(s.avoidFlood(rains), ans);
}