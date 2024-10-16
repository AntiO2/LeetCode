/**
 * @author Anti
 * @date 2024-01-08
 * @see https://leetcode.cn/problems/maximum-size-of-a-set-after-removals
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int maximumSetSize(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int,std::pair<int,int>> m1;
    int t1 = 0,t2=0;
    for(auto num:nums1) {
      if(m1.find(num)!=m1.end()) {
        m1[num].first++;
      } else {
        t1++;
        m1[num] = {1,0};
      }
    }
    for(auto num:nums2) {
      if(m1.count(num)) {
        if(m1[num].second==0) {
          t2++;
        }
        m1[num].second++;
      } else {
        t2++;
        m1[num] = {0,1};
      }
    }
    int c1=0,c2=0;
    auto n = nums2.size();
    std::vector< std::pair<int,std::pair<int,int>>> exist(m1.begin(),m1.end());
    std::sort(exist.begin(), exist.end(),
              [](const std::pair<int,std::pair<int,int>>&a,const std::pair<int,std::pair<int,int>>&b) {
                if(a.second.first*a.second.second==0) {
                  if(b.second.first*b.second.second==0) {
                    return false;
                  }
                  return true;
                }
                if(b.second.first*b.second.second==0) {
                  return false;
                }
                return (a.second.first+a.second.second) < (b.second.first+b.second.second);
              });
    for(auto&[a,b]:exist) {
      if(c1+c2==n) {
        break ;
      }
      if(b.first==0) {
        if(c2 < n/2) {
          t2--;
          c2++;
        }
        continue ;
      }
      if(b.second==0) {
        if(c1 < n/2) {
          t1--;
          c1++;
        }
        continue ;
      }
      // 1 1 3 4
      // 1 2 2 2
      if(c2==n/2) {
        c1++;
        continue ;
      }
      if(c1==n/2) {
        c2++;
        continue ;
      }
      c1++;
    }
    return c1+c2;
  }
}; // maximum-size-of-a-set-after-removals

TEST(testC, SAMPLE1) {
  Solution sol;
  auto s1 = std::vector{1,2,3,4,5,6};
  auto s2 = std::vector{2,3,2,3,2,3};
  EXPECT_EQ(sol.maximumSetSize(s1,s2),5);
}

TEST(testC, SAMPLE2) {
  Solution sol;
  auto s1 = std::vector{2,6,1,10,6,6,5,6};
  auto s2 = std::vector{2,7,7,10,9,1,9,4};
  EXPECT_EQ(sol.maximumSetSize(s1,s2),8);
}