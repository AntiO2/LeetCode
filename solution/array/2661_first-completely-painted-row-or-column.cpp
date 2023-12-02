/**
 * @author Anti
 * @date 2023-12-01
 * @see https://leetcode.cn/problems/first-completely-painted-row-or-column
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
    auto m = mat.size(), n = mat.at(0).size();
    auto l = arr.size();
    std::unordered_map<int,std::pair<int,int>> pos;
    for(int i = 0; i< m;i++) {
      for(int j = 0 ;  j < n; j++) {
        pos[mat[i][j]]=std::make_pair(i,j);
      }
    }
    std::vector<int> cnt_x(m,n);
    std::vector<int> cnt_y(n,m);
    for(auto i = 0 ; i < l; i++) {
      const auto [x,y] = pos[arr[i]];
      --cnt_x[x];
      --cnt_y[y];
      if(cnt_x[x]==0||cnt_y[y]==0) {
        return i;
      }
    }
    assert(false);
  }
};  // first-completely-painted-row-or-column

TEST(test2661, SAMPLE1) {
  Solution sol;
  std::vector nums{1,3,4,2};
  std::vector<std::vector<int>> mat{std::vector{1,4},std::vector{2,3}};
  EXPECT_EQ(sol.firstCompleteIndex(nums,mat),2);
}

TEST(test2661, SAMPLE2) {
  Solution sol;
}