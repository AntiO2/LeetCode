/**
 * @author Anti
 * @date 2023-11-19
 * @see https://leetcode.cn/problems/maximum-xor-product
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  static inline long long get_nth_bit(long long x,int n) {
    return x&(1LL<<n);
  }
  static constexpr int mod = 1e9+7;
 public:
  int maximumXorProduct(long long a, long long b, int n) {
    long long x = 0;
    if(a < b) {
      std::swap(a,b);
    }
    bool a_bigger = true;
    bool always_a_bigger = false;
    if((a>>n) > (b>>n)) {
      // const a > b
      always_a_bigger = true;
    }
    for(int i = n-1; i>=0; i--) {
      auto a_bit = get_nth_bit(a,i),b_bit = get_nth_bit(b,i);
      if(a_bit) {
        if(b_bit) {
          // x|=(1<<i);
        }
        if(!b_bit&&(a_bigger||always_a_bigger)) {
          // a = 1 && b = 0
          x|=(1LL<<i);
          a_bigger^=true;
        }
      } else {
        // a该位为0
        if(!b_bit) {
          // b该位为0
          x|=(1LL<<i);
        }
        if(b_bit&&!(a_bigger||always_a_bigger)) {
          // a = 0 && b = 1
          x|=(1LL<<i);
        }
      }
    }
    return ((a^x)%mod)* ((b^x)%mod)%mod;
  }
}; // maximum-xor-product

TEST(test2937, SAMPLE1) {
  Solution sol;
  int a = 12;
  int b = 5;
  int n = 4;
  EXPECT_EQ(sol.maximumXorProduct(a,b,n),98);
}

TEST(test2937, SAMPLE2) {
  Solution sol;
  int a = 6;
  int b = 7;
  int n = 5;
  EXPECT_EQ(sol.maximumXorProduct(a,b,n),930);
}
TEST(test2937, SAMPLE3) {
  Solution sol;
  int a = 1;
  int b = 6;
  int n = 3;
  EXPECT_EQ(sol.maximumXorProduct(a,b,n),12);
}
TEST(test2937, SAMPLE4) {
  Solution sol;
  int a = 0;
  int b = 7;
  int n = 2;
  EXPECT_EQ(sol.maximumXorProduct(a,b,n),12);
}
TEST(test2937, SAMPLE5) {
  Solution sol;
  int a = 2;
  int b = 5;
  int n = 5;
  EXPECT_EQ(sol.maximumXorProduct(a,b,n), 756);
}
TEST(test2937, SAMPLE6) {
  Solution sol;
  long long a = 570713374625622;
  long long b = 553376364476768;
  int n = 35;
  EXPECT_EQ(sol.maximumXorProduct(a,b,n), 756);
}

