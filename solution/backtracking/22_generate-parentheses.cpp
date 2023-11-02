/**
 * @author Anti
 * @date 2023/11/2
 * @see https://leetcode.cn/problems/generate-parentheses
 */

#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  void find_match(int max, int left, int right, std::list<char>& curr,
                  std::vector<std::string>& ans) {
    if (curr.size() == max * 2) {
      ans.emplace_back(curr.begin(), curr.end());
      return;
    }
    if (left > right) {
      curr.push_back(')');
      find_match(max, left, right + 1, curr, ans);
      curr.pop_back();
    }

    if (left < max) {
      curr.push_back('(');
      find_match(max, left + 1, right, curr, ans);
      curr.pop_back();
    }
  }

 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::list<char> tmp;
    std::vector<std::string> ans;
    find_match(n, 0, 0, tmp, ans);
    return ans;
  }
};

TEST(test22, SAMPLE1) {
  Solution sol;
  sol.generateParenthesis(3);
}

TEST(test22, SAMPLE2) {
  Solution sol;
}