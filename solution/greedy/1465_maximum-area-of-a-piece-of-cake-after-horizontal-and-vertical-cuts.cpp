/**
 * @author Anti
 * @date 2023/10/27
 * @see
 * https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts
 */

#include <algorithm>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  static constexpr int mod = 1e9 + 7;

 public:
  int maxArea(int h, int w, std::vector<int>& horizontalCuts,
              std::vector<int>& verticalCuts) {
    horizontalCuts.push_back(0);
    horizontalCuts.push_back(h);
    verticalCuts.push_back(0);
    verticalCuts.push_back(w);
    std::ranges::sort(horizontalCuts);
    std::ranges::sort(verticalCuts);
    int h_length = 0, v_length = 0;
    for (int i = 1; i < horizontalCuts.size(); ++i) {
      h_length = std::max(h_length, horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    for (int i = 1; i < verticalCuts.size(); ++i) {
      v_length = std::max(v_length, verticalCuts[i] - verticalCuts[i - 1]);
    }
    return int(((h_length * 1LL) * (v_length * 1LL)) % mod);
  }
};

/**
 * Sort
 */
class Solution2 {
 private:
  static constexpr int mod = 1e9 + 7;

 public:
  int maxArea(int h, int w, std::vector<int>& horizontalCuts,
              std::vector<int>& verticalCuts) {

    std::vector<int> h_length(horizontalCuts.size());
    std::vector<int> v_length(verticalCuts.size());
    std::ranges::sort(horizontalCuts);
    std::ranges::sort(verticalCuts);
    if (horizontalCuts.empty()) {
      horizontalCuts.push_back(h);
    } else {
      h_length[0] = horizontalCuts[0];
      std::transform(horizontalCuts.begin() + 1, horizontalCuts.end(),
                     horizontalCuts.begin(), h_length.begin() + 1,
                     [](int h1, int h2) { return h1 - h2; });
      h_length.push_back(h - horizontalCuts.back());
    }
    if (verticalCuts.empty()) {
      verticalCuts.push_back(h);
    } else {
      v_length[0] = verticalCuts[0];
      std::transform(verticalCuts.begin() + 1, verticalCuts.end(),
                     verticalCuts.begin(), v_length.begin() + 1,
                     [](int v1, int v2) { return v1 - v2; });
      v_length.push_back(w - verticalCuts.back());
    }
    std::ranges::sort(h_length, std::greater());
    std::ranges::sort(v_length, std::greater());
    return int(((h_length[0] * 1LL) * (v_length[0] * 1LL)) % mod);
  }
};

TEST(test1465, SAMPLE1) {
  Solution sol;
  int h = 5;
  int w = 4;
  std::vector hc{1, 2, 4};
  std::vector vc{1, 3};
  EXPECT_EQ(sol.maxArea(h, w, hc, vc), 4);
}

TEST(test1465, SAMPLE2) {
  Solution sol;
}