/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/decode-string
 */

#include <stack>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  std::string getDigits(std::string& s, size_t& ptr) {
    std::string ret{};
    while (isdigit(s[ptr])) {
      ret.push_back(s[ptr++]);
    }
    return ret;
  }
  std::string getString(std::vector<std::string>& ss) {
    std::string ret = "";
    for (auto& s : ss) {
      ret += s;
    }
    return ret;
  }

 public:
  std::string decodeString(std::string s) {
    std::string ans;
    std::vector<std::string> stk;
    size_t ptr = 0;
    while (ptr < s.size()) {
      char curr = s[ptr];
      if (isdigit(curr)) {
        stk.push_back(getDigits(s, ptr));
      } else if (isalpha(curr) || curr == '[') {
        stk.emplace_back(1, s[ptr++]);
      } else {
        // 右括号
        std::vector<std::string> sub;
        while (stk.back() != "[") {
          sub.emplace_back(stk.back());
          stk.pop_back();
        }
        std::reverse(sub.begin(), sub.end());  // 获得待拼接的多个字符串
        stk.pop_back();                        // 弹出左括号
        auto times = std::stoi(stk.back());
        stk.pop_back();
        std::string t;
        auto o = getString(sub);
        for (int i = 0; i < times; ++i) {
          t += o;
        }
        stk.push_back(t);
        ++ptr;
      }
    }
    return getString(stk);
  }
};
TEST(test394, SAMPLE1) {
  Solution sol;
  std::string s{"3[a]2[bc]"};
  EXPECT_EQ(sol.decodeString(s), "aaabcbc");
}

TEST(test394, SAMPLE2) {
  Solution sol;
}