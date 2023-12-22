/**
 * @author Anti
 * @date 2023-12-22
 * @see
 * https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int minimumMountainRemovals(std::vector<int>& nums) {
    auto n = nums.size();
    std::vector<int> left;
    std::vector<int> right;
    std::vector<int> left_length;
    std::vector<int> right_length;
    for(auto num:nums) {
      auto pos = std::lower_bound(left.begin(), left.end(), num);
      if(pos==left.end()) {
        left.emplace_back(num);
        left_length.emplace_back(left.size());
      } else {
        *pos = num;
        left_length.emplace_back(std::distance(left.begin(),pos) + 1);
      }

    }
    std::reverse(nums.begin(), nums.end());
    for(auto num:nums) {
      auto pos = std::lower_bound(right.begin(), right.end(), num);
      if(pos==right.end()) {
        right_length.emplace_back(right.size());
        right.emplace_back(num);
      } else {
        *pos = num;
        right_length.emplace_back(std::distance(right.begin(),pos) );
      }

    }
    std::reverse(right_length.begin(), right_length.end());
    int ans = 0;
    for(int i = 0;i<n;i++) {
      if(right_length[i]+left_length[i]>ans&&left_length[i]!=1&&right_length[i]!=0) {
        ans  = right_length[i]+left_length[i];
      }
    }
    return n-ans;
  }
};  // minimum-number-of-removals-to-make-mountain-array

TEST(test1671, SAMPLE1) {
  Solution sol;
  auto nums=std::vector{1,3,1};
  EXPECT_EQ(sol.minimumMountainRemovals(nums),0);
}

TEST(test1671, SAMPLE2) {
  Solution sol;
  auto nums=std::vector{4,3,2,1,1,2,3,1}; //  x x x x 1 2 3 1
  EXPECT_EQ(sol.minimumMountainRemovals(nums),4);
}
TEST(test1671, SAMPLE3) {
  Solution sol;
  auto nums=std::vector{9,8,1,7,6,5,4,3,2,1}; //  x x 1,7,6,5,4,3,2,1
  EXPECT_EQ(sol.minimumMountainRemovals(nums),2);
}