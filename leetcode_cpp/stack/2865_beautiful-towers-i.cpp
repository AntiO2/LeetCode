/**
 * @author Anti
 * @date 2024-01-24
 * @see https://leetcode.cn/problems/beautiful-towers-i
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <stack>
class Solution {
 public:
  long long maximumSumOfHeights(std::vector<int>& maxHeights) {
    auto n = maxHeights.size();
    std::vector<long long> left(n),right(n);
    std::stack<std::pair<int,int>> stk_;
    for(size_t i = 0; i < n; i++) {
      while(!stk_.empty()&&stk_.top().first > maxHeights[i]) {
        stk_.pop();
      }
      if(stk_.empty()) {
        left[i] = (long long) (i + 1) * maxHeights[i];
      } else {
        left[i] = (long long)(i - stk_.top().second)* maxHeights[i] + left[stk_.top().second];
      }
      stk_.emplace(maxHeights[i],i);
    }

    while (!stk_.empty()) {stk_.pop();}
    std::reverse(maxHeights.begin(), maxHeights.end());
    for(size_t i = 0; i < n; i++) {
      while(!stk_.empty()&&stk_.top().first > maxHeights[i]) {
        stk_.pop();
      }
      if(stk_.empty()) {
        right[i] = (long long)(i + 1) * maxHeights[i];
      } else {
        right[i] = (long long)(i - stk_.top().second)* maxHeights[i] + right[stk_.top().second];
      }
      stk_.emplace(maxHeights[i],i);
    }
    std::reverse(right.begin(), right.end());
    std::reverse(maxHeights.begin(), maxHeights.end());
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      ans = std::max(ans, left[i] + right[i] - maxHeights[i]);
    }
    return ans;
  }
}; // beautiful-towers-i

TEST(test2865, SAMPLE1) {
  Solution sol;
}

TEST(test2865, SAMPLE2) {
  Solution sol;
}