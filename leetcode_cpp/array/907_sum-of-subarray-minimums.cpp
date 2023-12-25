/**
 * @author Anti
 * @date 2023-11-27
 * @see https://leetcode.cn/problems/sum-of-subarray-minimums
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <queue>
#include <stack>
class Solution {
 static constexpr int mod = 1e9+7;
 public:
  int sumSubarrayMins(std::vector<int>& arr) {
    std::stack<std::pair<int,int>> stk;
    std::stack<std::pair<int,int>> right_stk;
    auto n  = arr.size();
    long long ans = 0;
    stk.emplace(-1,0);
    std::vector<int> left_len(n);
    for(int i = 0; i < n;i++) {
      auto now = arr[i];
      while(stk.top().second >= now) {
        stk.pop();
      }
      left_len[i] = i - stk.top().first;
      stk.emplace(i,now);
    }
    right_stk.emplace(n,0);
    for(int i = n-1; i >= 0;i--) {
      auto now = arr[i];
      while(right_stk.top().second > now) {
        right_stk.pop();
      }
      ans+= ((long long)(right_stk.top().first-i)*left_len[i]%mod)*now%mod;
      ans%=mod;
      right_stk.emplace(i,now);
    }
    return ans;
  }
}; // sum-of-subarray-minimums

TEST(test907, SAMPLE1) {
  Solution sol;
  std::vector ans{3,1,2,4};
  EXPECT_EQ(sol.sumSubarrayMins(ans), 17);
}

TEST(test907, SAMPLE2) {
  Solution sol;
}