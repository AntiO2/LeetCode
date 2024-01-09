/**
 * @author Anti
 * @date 2024-01-08
 * @see https://leetcode.cn/problems/number-of-boomerangs
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
    int n = points.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
      std::unordered_map<int,int> dis;
      for(int j = 0 ; j<n;j++) {
        if(i==j) {
          continue ;
        }
        dis[(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1])]++;
      }
      for(auto &[a,cnt]:dis) {
        ans+=cnt*(cnt-1);
      }
    }
    return ans;
  }

}; // number-of-boomerangs

TEST(test447, SAMPLE1) {
  Solution sol;
}

TEST(test447, SAMPLE2) {
  Solution sol;
}