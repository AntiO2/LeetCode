/**
 * @author Anti
 * @date 2024-01-07
 * @see https://leetcode.cn/problems/minimum-moves-to-capture-the-queen
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        auto min_step = 2;
        if((c+d)==(e+f)) {
          if(!(a+b==c+d&&a>std::min(c,e)&&a<std::max(c,e))) {
            min_step = 1;
          }
        }
        if(e-c==f-d) {
          auto d1 = e-c;
          auto d2 = e-a;
          if(!(e-a==f-b&&(d1*d2>0)&&std:: abs(d2)<std::abs(d1))) {
            min_step = 1;
          }
        }
        if(a==e&&(a!=c||(a==c&&(d>std::max(b,f)||d<std::min(b,f))))) {
          min_step=1;
        }
        if(b==f&&(b!=d||(b==d&&(c>std::max(a,e)||c<std::min(a,e))))) {
          min_step=1;
        }
        return min_step;
  }
}; // minimum-moves-to-capture-the-queen

TEST(testB, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(1,1,1,2,1,3),2);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(1,1,2,2,1,3),1);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(1,1,1,0,1,3),1);

  EXPECT_EQ(sol.minMovesToCaptureTheQueen(1,1,2,1,3,1),2);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(1,1,5,1,3,1),1);

  EXPECT_EQ(sol.minMovesToCaptureTheQueen(1,1,4,1,3,2),1);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(2,2,1,1,3,3),2);

  EXPECT_EQ(sol.minMovesToCaptureTheQueen(4,4,1,1,3,3),1);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(4,4,5,5,3,3),2);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(2,2,5,5,3,3),1);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(2,2,1,1,3,3),2);

  EXPECT_EQ(sol.minMovesToCaptureTheQueen(4,3,3,4,5,2),2);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(2,5,3,4,6,1),1);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(3,3,3,4,6,1),1);

  EXPECT_EQ(sol.minMovesToCaptureTheQueen(7,0,3,4,6,1),1);
  EXPECT_EQ(sol.minMovesToCaptureTheQueen(2,7,3,4,6,1),1);
}

TEST(testB, SAMPLE2) {
  Solution sol;
}