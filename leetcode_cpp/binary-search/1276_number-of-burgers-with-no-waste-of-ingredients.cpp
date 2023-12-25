/**
 * @author Anti
 * @date 2023-12-25
 * @see
 * https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <vector>
class Solution {
 private:
  inline int getTomoato(int big,int small) {
    return big*4+small*2;
  }
 public:
  std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    int l = 0, r  = cheeseSlices; // 二分求巨无霸的个数
    while(l<=r) {
      int mid = (l+r)>>1;
      int small = cheeseSlices - mid;
      auto num = getTomoato(mid,small);
      // LOG_DEBUG("%d %d %d",mid,small,num);
      if(num==tomatoSlices) {
        return {mid,small};
      }
      if(num>tomatoSlices) {
        r = mid - 1;
      } else {
        l = mid+1;
      }
    }
    return {};
  }
};  // number-of-burgers-with-no-waste-of-ingredients

TEST(test1276, SAMPLE1) {
  Solution sol;
  std::vector<int> ans{776,429};
  EXPECT_EQ(sol.numOfBurgers(3962,1205),ans);
}

TEST(test1276, SAMPLE2) {
  Solution sol;

  std::vector<int> ans{0,0};
  EXPECT_EQ(sol.numOfBurgers(0,0),ans);
}