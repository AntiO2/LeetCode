//
// Created by Anti on 2023/9/30.
//
#include <list>
#include <numeric>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
/*
 * 1.
 * 可以证明，开始种一株花，最好连续种完。假设i在j之前种完，那么j完全生长的时间是固定的(plant
 * i+ plant j + grow j)
 *      对于i来说，如果种植时没有穿插j的种植，才能尽可能早的开花。
 * 2.
 * 假设前面的种植已经完成，现在还剩i和j两株花，且i比j先种。那么从这刻开始理论上的完全开花时间是max(plant
 * i + grow i, plant i + plant j + grow j)
 *
 * 3.   若i和j可以交换，说明交换后结果更优。 max(plant i + grow i, plant i +
 * plant j + grow j) > max(p j + g j , p j + p i + g i) pi + max(g i,pj + g j) >
 * pj + max(gj, pi + g i)
 *
 * 4.   考虑何时该不等式成立，也就是i在什么时候应该在j前面。
 *
 *      可以证明g i < g j 时，不等式成立。此时j应该 在i之前种植。
 * 5.   如果gi = gj
 *      pi + pj + gi > pj + pi + gi -> 0 > 0
 *      可以说此时先种谁都无所谓。（因为按照第一点，最后的生长时间总是plant i+
 * plant j + grow i/j）
 */
class Solution {
 public:
  int earliestFullBloom(std::vector<int>& plantTime,
                        std::vector<int>& growTime) {
    auto n = growTime.size();
    std::vector<int> index(n);
    std::iota(index.begin(), index.end(), 0);
    std::sort(index.begin(), index.end(),
              [&growTime](const int& a, const int& b) {
                return growTime[a] > growTime[b];
              });
    int ans = 0;
    int prev = 0;  // 种植时间
    for (int i = 0; i < n; i++) {
      auto id = index[i];
      prev += plantTime[id];
      ans = std::max(ans, prev + growTime[id]);
    }
    return ans;
  }
};

TEST(test2136, SAMPLE1) {
  Solution s;
  auto a = std::vector<int>{1, 4, 3};
  auto b = std::vector<int>{2, 3, 1};
  EXPECT_EQ(s.earliestFullBloom(a, b), 9);
}

TEST(test2136, SAMPLE2) {
  Solution s;
  auto a = std::vector<int>{1, 2, 3, 2};
  auto b = std::vector<int>{2, 1, 2, 1};
  EXPECT_EQ(s.earliestFullBloom(a, b), 9);
}
TEST(test2136, SAMPLE3) {
  Solution s;
  auto a = std::vector<int>{1};
  auto b = std::vector<int>{1};
  EXPECT_EQ(s.earliestFullBloom(a, b), 2);
}