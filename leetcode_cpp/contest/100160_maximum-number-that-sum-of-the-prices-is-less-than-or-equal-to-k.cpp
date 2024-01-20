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
 public:
  long long check(long long mid,int x)
  {
    if(mid==0)return 0;
    if(mid==1&&x==1)return 1;
    if(mid==1&&x!=1)return 0;
    int mw; // 最高位数。
    for(int i=0;i<64;i++)
      if(mid>>i&1) {
        mw=i;
      }
    long long res=0;
    res=mw/x;
    res=res*(1ll<<(mw-1));
    if((mw+1)%x==0)res=res+(mid-(1ll<<mw)+1);
    long long y=0;
    y=mid-(1ll<<mw);
    res+=check(y,x);
    return res;
  }
  long long findMaximumNumber(long long k, int x) {
    long long l=1,r=k*(1<<x);
    while(l<r)
    {
      long long mid=(l+r+1)>>1;
      if(check(mid,x)<=k) {
        l=mid;
      }
      else r=mid-1;
    }
    return l;
  }
};
TEST(test100160, SAMPLE1) {
  Solution sol;
}

TEST(test100160, SAMPLE2) {
  Solution sol;
}