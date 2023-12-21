/**
 * @author Anti
 * @date 2023-12-21
 * @see https://leetcode.cn/problems/beautiful-towers-ii
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <stack>
class Solution {
 public:
  long long maximumSumOfHeights(std::vector<int>& maxHeights) {
    int n = maxHeights.size();
    std::vector<long long> left(n), right(n);
    std::stack<std::pair<int,int>> stk_; // 从左到右，递增的程序栈。
    for(long long  i = 0 ; i < n; i++) {
      while (!stk_.empty()&&stk_.top().first>=maxHeights[i]) {
        stk_.pop();
      }
      if(stk_.empty()) {
        // 说明i之前的max heights都比它大（被弹出）
        left[i] = (i+1) * maxHeights[i];
      } else {
        left[i] = left[stk_.top().second] +
                  (i-stk_.top().second) * maxHeights[i];
      }
      stk_.emplace(maxHeights[i],i);
    }
    stk_ = std::stack<std::pair<int,int>>();
    for(long long  i = n-1;i>=0;i--) {
      while (!stk_.empty()&&stk_.top().first>=maxHeights[i]) {
        stk_.pop();
      }
      if(stk_.empty()) {
        right[i] = (n-i) *maxHeights[i];
      } else {
        right[i] = right[stk_.top().second] + (stk_.top().second - i ) * maxHeights[i];
      }
      stk_.emplace(maxHeights[i],i);
    }
    long long ans = 0;
    for(int i = 0 ; i< n;i++) {
      ans = std::max(ans, left[i] + right[i] - maxHeights[i]);
    }
    return ans;
  }
}; // beautiful-towers-ii

TEST(test2866, SAMPLE1) {
  Solution sol;
  std::vector<int> maxHeights{5,3,4,1,1};
  EXPECT_EQ(sol.maximumSumOfHeights(maxHeights),13);
}

TEST(test2866, SAMPLE2) {
  Solution sol;
}