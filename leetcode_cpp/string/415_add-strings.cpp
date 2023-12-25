/**
 * @author Anti
 * @date 2023-12-23
 * @see https://leetcode.cn/problems/add-strings
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::string addStrings(std::string num1, std::string num2) {
    std::vector<char> ans;
    if(num1.size()<num2.size()) {
      std::swap(num1,num2);
    }
    // Now, num1.size() >= num2.size()
    int iter1 = num1.size()-1;
    int iter2 = num2.size()-1;
    bool c = false;
    while (iter2>=0) {
      int now = num1[iter1]-'0' + num2[iter2]-'0' + (c?1:0);
      if(now >=10) {
        c = true;
        now-=10;
      } else {
        c = false;
      }
      ans.push_back(now);
      --iter1;
      --iter2;
    }
    while(iter1>=0) {
      int now = num1[iter1]-'0' + (c?1:0);
      if(now >=10) {
        c = true;
        now-=10;
      } else {
        c = false;
      }
      ans.push_back(now);
      --iter1;
    }
    if(c) {
      ans.push_back(1);
    }
    // 得到了结果的数位，将其转化为string
    std::stringstream ss;
    for(auto iter = ans.rbegin(); iter!=ans.rend(); ++iter) {
      ss << char(*iter+'0');
    }
    std::string ans_string;
    ss>>ans_string;
    return ans_string;
  }
};  // add-strings

TEST(test415, SAMPLE1) {
  Solution sol;
  std::string num1{"123"},num2{"11"};
  EXPECT_EQ(sol.addStrings(num1,num2),"134");
}

TEST(test415, SAMPLE2) {
  Solution sol;
}