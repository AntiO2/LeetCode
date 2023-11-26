/**
 * @author Anti
 * @date 2023-11-26
 * @see https://leetcode.cn/problems/c
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

#include <vector>
#include <unordered_map>

class Solution {
  int find(int i, std::vector<int>&fa){
    if(i==fa[i]) {
      return i;
    }
    return fa[i] = find(fa[i],fa);
  }
  void join(int i,int j,std::vector<int>&fa) {
    auto fi = find(i,fa),fj = find(j,fa);
    if(fi<fj) {
      fa[fj] = fi;
    } else {
      fa[fi] = fj;
    }
  }

 public:
  std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
    int n = nums.size();
    std::vector<int> ans(n);
    std::vector<std::pair<int,int>> group(n);
    std::vector<int>fa(n);
    for(int i = 0 ; i <  n;i++) {
      fa[i] = i;
      group[i].first = nums[i];
      group[i].second = i;
    }
    std::sort(group.begin(), group.end());
    for(int i = 1; i < n; i++) {
      if(group[i].first-group[i-1].first<=limit) {
        join(group[i].second, group[i-1].second,fa);
      }
    }
    std::unordered_map<int,std::vector<std::pair<int,int>>> count;
    for(int i = 0 ; i < n;i++) {
      count[find(group[i].second,fa)].emplace_back(group[i]);
    }
    for(auto iter:count) {
      auto & tmp = iter.second;
      std::sort(tmp.begin(), tmp.end());
      std::vector<int> value(tmp.size());
      for(int i  = 0 ; i <tmp.size();i++) {
        value[i] = tmp[i].first;
      }
      std::sort(tmp.begin(), tmp.end(),[](auto&t1,auto&t2) {
        return t1.second<t2.second;
      });
      for(int i  = 0 ; i <tmp.size();i++) {
        ans[tmp[i].second] = value[i];
      }
    }
    return ans;
  }
};

TEST(test3, SAMPLE1) {
  Solution sol;
  std::vector nums{5,4,3,2,1};
  int limit = 1;
  std::vector ans {1,2,3,4,5};
  EXPECT_EQ(sol.lexicographicallySmallestArray(nums,limit),ans);
}

TEST(test3, SAMPLE2) {
  Solution sol;
  std::vector nums{1,60,34,84,62,56,39,76,49,38};
  int limit = 4;
  std::vector ans {1,56,34,84,60,62,38,76,49,39};
  EXPECT_EQ(sol.lexicographicallySmallestArray(nums,limit),ans);
}

TEST(test3, SAMPLE3) {
  Solution sol;
  std::vector nums{3,2,1};
  int limit = 1;
  std::vector ans {1,2,3};
  EXPECT_EQ(sol.lexicographicallySmallestArray(nums,limit),ans);
}