/**
 * @author Anti
 * @date 2024-01-20
 * @see https://leetcode.cn/problems/minimize-length-of-array-using-operations
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <queue>

class Solution {
 public:
  int minimumArrayLength(std::vector<int>& nums) {
    std::sort(nums.begin(),nums.end());
    int cnt = 0;
    int t = nums[0];
    for(auto num:nums) {
      if(num==t) {
        cnt++;
      } else {
        break ;
      }
    }
    // 2 2 2 2 5 8
    std::priority_queue<int> pq(nums.begin(),nums.end());
    while(!pq.empty()) {
     auto a = pq.top();
     pq.pop();
     while(!pq.empty()&&pq.top()==a) {
       pq.pop();
     }
     if(pq.empty()) {
       break ;
     }
     auto b = pq.top();
     auto c = a%b;

     if(c) {
       if(c<t) {
         cnt = 1;
         break ;
       }
       pq.emplace(c);
     }
    }
    return (cnt+1)/2;
  }
}; // minimize-length-of-array-using-operations

TEST(test100164, SAMPLE1) {
  Solution sol;
}

TEST(test100164, SAMPLE2) {
  Solution sol;
}