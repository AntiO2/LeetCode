/**
 * @author Anti
 * @date 2023-11-19
 * @see https://leetcode.cn/problems/make-three-strings-equal
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int findMinimumOperations(std::string s1, std::string s2, std::string s3) {
    int l1 = s1.size(),l2 = s2.size(), l3 = s3.size();
    int i = 0;
    while(i < l1&&i<l2&&i<l3) {
      if(s1[i]==s2[i]&&s2[i]==s3[i]) {
        ++i;
      } else {
        break;
      }
    }
    int ans = -1;
    if(i>=1) {
      ans  =l1+l2+l3-i*3;
    }
    return ans;
  }
}; // make-three-strings-equal

TEST(test100131, SAMPLE1) {
  Solution sol;
  std::string s1 = "abc",s2 = "abb",s3 = "ab";
  EXPECT_EQ(sol.findMinimumOperations(s1,s2,s3),2);
}

TEST(test100131, SAMPLE2) {
  Solution sol;
  std::string s1 = "dac",s2 = "bac",s3 = "cac";
  EXPECT_EQ(sol.findMinimumOperations(s1,s2,s3),-1);
}
TEST(test100131, SAMPLE3) {
  Solution sol;
  std::string s1 = "a",s2 = "a",s3 = "a";
  EXPECT_EQ(sol.findMinimumOperations(s1,s2,s3),0);
}
TEST(test100131, SAMPLE4) {
  Solution sol;
  std::string s1 = "a",s2 = "a",s3 = "ab";
  EXPECT_EQ(sol.findMinimumOperations(s1,s2,s3),1);
}
TEST(test100131, SAMPLE5) {
  Solution sol;
  std::string s1 = "a",s2 = "ac",s3 = "ab";
  EXPECT_EQ(sol.findMinimumOperations(s1,s2,s3),2);
}