/**
 * @author Anti
 * @date 2023-12-16
 * @see https://leetcode.cn/problems/count-integers-in-intervals
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class CountIntervals {
 public:
  CountIntervals() {

  }

  void add(int left, int right) {

  }

  int count() {

  }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */  // count-integers-in-intervals

TEST(test2276, SAMPLE1) {
  CountIntervals* obj = new CountIntervals();
  obj->add(2,3);
  obj->add(7,10);
  EXPECT_EQ(obj->count(),6);
  obj->add(5,8);
  EXPECT_EQ(obj->count(), 8);
  delete obj;
}

TEST(test2276, SAMPLE2) {
  CountIntervals* obj = new CountIntervals();



  delete obj;
}