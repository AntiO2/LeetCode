/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/largest-rectangle-in-histogram
 */

#include <stack>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    int n = heights.size();
    std::vector<int> left(n), right(n);

    std::stack<int> mono_stack;
    for (int i = 0; i < n; ++i) {
      while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
        right[mono_stack.top()] = i;
        mono_stack.pop();  // 将所有左侧无用的弹出
      }
      left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
      mono_stack.push(i);
    }
    int ans = 0;
    while (!mono_stack.empty()) {
      // 因为栈里面单调递增。所以最后没出栈的，左边界都在最右侧。
      right[mono_stack.top()] = n;
      mono_stack.pop();
    }
    for (int i = 0; i < n; ++i) {
      ans = std::max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
  }
};

TEST(test84, SAMPLE1) {
  Solution sol;
  std::vector h{2, 4};
  EXPECT_EQ(sol.largestRectangleArea(h), 4);
}

TEST(test84, SAMPLE2) {
  Solution sol;
}