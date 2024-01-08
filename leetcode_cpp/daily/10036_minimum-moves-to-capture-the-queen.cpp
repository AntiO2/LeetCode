/**
 * @author Anti
 * @date 2024-01-08
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