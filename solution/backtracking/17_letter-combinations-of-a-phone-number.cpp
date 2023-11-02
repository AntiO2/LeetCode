/**
 * @author Anti
 * @date 2023/11/1
 * @see https://leetcode.cn/problems/letter-combinations-of-a-phone-number
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  const std::map<char, std::vector<char>> digital_char{
      {'2', std::vector{'a', 'b', 'c'}},
      {'3', std::vector{'d', 'e', 'f'}},
      {'4', std::vector{'g', 'h', 'i'}},
      {'5', std::vector{'j', 'k', 'l'}},
      {'6', std::vector{'m', 'n', 'o'}},
      {'7', std::vector{'p', 'q', 'r', 's'}},
      {'8', std::vector{'t', 'u', 'v'}},
      {'9', std::vector{'w', 'x', 'y', 'z'}}};

  void dfs(int step, std::string& digits, std::vector<std::string>& ans,
           std::string& curr, int max) {
    if (step == max) {
      ans.emplace_back(curr);
      return;
    }
    auto list = digital_char.find(digits[step])->second;
    for (auto& c : list) {
      curr[step] = c;
      dfs(step + 1, digits, ans, curr, max);
    }
  }

 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> ans{};
    if (digits.empty()) {
      return ans;
    }
    auto l = digits.length();
    std::string curr(l, ' ');
    dfs(0, digits, ans, curr, l);
    return ans;
  }
};  // fill in it

TEST(test17, SAMPLE1) {
  Solution sol;
  sol.letterCombinations("23");
}

TEST(test17, SAMPLE2) {
  Solution sol;
}