/**
 * @author Anti
 * @date 2023-11-20
 * @see https://leetcode.cn/problems/find-building-where-alice-and-bob-can-meet
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <numeric>
#include <queue>
class Solution {
 private:
  using height_t = int;
  using pos_t = int;
  struct build {
    height_t height;
    pos_t pos;
  };
 public:
  std::vector<int> leftmostBuildingQueries(std::vector<int>& heights, std::vector<std::vector<int>>& queries) {
    std::vector<int> query_idx(queries.size());
    std::vector<int> ret(queries.size());
    std::iota(query_idx.begin(), query_idx.end(),0);
    std::for_each(queries.begin(), queries.end(),[](auto &query) {
      if(query[0] > query[1]) {
        std::swap(query[0] ,query[1]);
      }
    });
    std::sort(query_idx.begin(), query_idx.end(),[&queries](const int i1, const int i2) {
      return queries[i1][1] > queries[i2][1]; // 离线查询，根据右侧节点排序。
    });
    std::deque<build> stk;
    int iter = heights.size()-1;

    for(auto i:query_idx) {
      auto left = queries[i][0], right = queries[i][1];
      while(iter>=0&&iter >=right) {
        auto height = heights[iter];
        while(!stk.empty()&&stk.front().height <= height) {
          stk.pop_front();
        }
        stk.push_front({.height = height,.pos = iter});
        --iter;
      }
      if(left==right) {
        ret[i] = left;
        continue ;
      }
      if(heights[left] < heights[right]) {
        ret[i] = right;
        continue ;
      }
      auto target = std::upper_bound(stk.begin(), stk.end(), build{.height=std::max(heights[left],heights[right]),.pos=-1},
                                     [](auto &info1,auto &info2) {return info1.height < info2.height;});
      if(target==stk.end()) {
        ret[i] = -1;
      } else {
        ret[i] = target->pos;
      }
    }
    return ret;
  }
};  // find-building-where-alice-and-bob-can-meet

TEST(test2940, SAMPLE1) {
  Solution sol;
  std::vector h{6,4,8,5,2,7};
  std::vector<std::vector<int>> query{std::vector{0,1}};
  EXPECT_EQ(sol.leftmostBuildingQueries(h,query),std::vector{2});
}

TEST(test2940, SAMPLE2) {
  Solution sol;
  std::vector h{1,2,1,2,1,2};
  std::vector<std::vector<int>> query{std::vector{0,2}};
  EXPECT_EQ(sol.leftmostBuildingQueries(h,query),std::vector{-1});
}