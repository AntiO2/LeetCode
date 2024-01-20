/**
 * @author Anti
 * @date 2024-01-18
 * @see https://leetcode.cn/problems/removing-minimum-number-of-magic-beans
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <numeric>
class Solution {
 public:
  long long minimumRemoval(std::vector<int>& beans) {
        long long ans = 0;
        ans = std::accumulate(beans.begin(),beans.end(),ans);
        std::sort(beans.begin(), beans.end(),std::greater<int>{});
        long long cost_to_zero = ans - beans[0];
        long long cost_to_line = 0;
        long long line = beans[0];
        ans = cost_to_zero;
        int n = beans.size();
        for(int i = 1; i < n;i++) {
          cost_to_line+=(line-beans[i])*i;
          line = beans[i];
          cost_to_zero-=beans[i];
          // LOG_INFO("Line is %lld cost is %lld",line,cost_to_line+cost_to_zero);
          ans = std::min(ans,cost_to_zero+cost_to_line);
        }
        return ans;
  }
};  // removing-minimum-number-of-magic-beans

TEST(test2171, SAMPLE1) {
  Solution sol;
  std::vector nums{4,1,6,5};
  sol.minimumRemoval(nums);
}

TEST(test2171, SAMPLE2) {
  Solution sol;
  std::vector nums{66,90,47,25,92,90,76,85,22,3};
  sol.minimumRemoval(nums);
}