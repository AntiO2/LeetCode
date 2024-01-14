/**
 * @author Anti
 * @date 2024-01-14
 * @see
 * https://leetcode.cn/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  long long tot(int i,int x) {
    long long cnt;
    if(i==1&&x==1) {
      return 1;
    }
    long long unit = (1<<(i-1))>>1;
    auto remain = i/x;
    cnt =  remain*unit;
    if(i%x==0) {
      cnt+=unit;
    }
    return cnt;
  }
  long long tot2(int i,int x) {
    // 求i位的value
    long long cnt;
    long long unit =  (1<<(i-1));
    auto remain = i/x;
    cnt =  remain*unit;
    return cnt;
  }
 public:
  long long findMaximumNumber(long long k, int x) {
    int i = 0;
    long long ans = 0;
    long long value = 0;
    while(true) {
      i++; // 目前判断第i位。
      long long cnt = tot(i,x);
      if(value + cnt < k) {
        value +=cnt;
        continue ;
      }
      // value <= k, value + cnt > k;
      ans = 1<<(i-1);
      auto flag = ans%x;
      while (value<k) {
        for(int j = 1; j < i; j++) {
          auto cnt2 = tot2(j,x);
          if(value+ cnt2<k) {
            value+= cnt2;
            continue ;
          }
          // 第j位固定为0.
          if(value+ tot2())
        }
      }
      return
    }
  }
};  // maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k

TEST(test100160, SAMPLE1) {
  Solution sol;
}

TEST(test100160, SAMPLE2) {
  Solution sol;
}