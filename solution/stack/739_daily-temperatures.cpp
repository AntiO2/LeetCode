/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/daily-temperatures
 */

#include <stack>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::vector<int> ans;
    std::stack<std::pair<int, int>> stk_;  // 保存温度和天数；
    ans.reserve(temperatures.size());
    auto ptr = temperatures.size();
    while (ptr--) {
      while (!stk_.empty() && stk_.top().first <= temperatures[ptr]) {
        stk_.pop();
      }
      if (stk_.empty()) {
        ans.push_back(0);
      } else {
        ans.push_back(stk_.top().second - ptr);
      }
      stk_.emplace(temperatures[ptr], ptr);
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
TEST(test739, SAMPLE1) {
  Solution sol;
  std::vector tmp{73, 74, 75, 71, 69, 72, 76, 73};
  sol.dailyTemperatures(tmp);
}

TEST(test739, SAMPLE2) {
  Solution sol;
  std::vector tmp{89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
  sol.dailyTemperatures(tmp);
}