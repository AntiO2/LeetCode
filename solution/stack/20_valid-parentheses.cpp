/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/valid-parentheses
 */

#include <stack>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  inline bool checkIsLeft(char c) { return c == '(' || c == '[' || c == '{'; }
  inline bool checkMatch(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') ||
           (a == '[' && b == ']');
  }

 public:
  bool isValid(std::string s) {
    std::stack<char> bracket;
    bool flag = true;
    for (auto c : s) {
      if (checkIsLeft(c)) {
        bracket.push(c);
      } else {
        if (bracket.empty()) {
          flag = false;
          break;
        }
        if (!checkMatch(bracket.top(), c)) {
          flag = false;
          break;
        }
        bracket.pop();
      }
    }
    if (!bracket.empty()) {
      flag = false;
    }
    return flag;
  }
};
TEST(test20, SAMPLE1) {
  Solution sol;
}

TEST(test20, SAMPLE2) {
  Solution sol;
}