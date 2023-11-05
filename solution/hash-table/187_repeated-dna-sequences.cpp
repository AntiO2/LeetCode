/**
 * @author Anti
 * @date 2023/11/5
 * @see https://leetcode.cn/problems/repeated-dna-sequences
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
  const int L = 10;

 public:
  std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> ans;
    std::unordered_map<std::string, int> cnt;
    int n = s.length();
    for (int i = 0; i <= n - L; ++i) {
      std::string sub = s.substr(i, L);
      if (++cnt[sub] == 2) {
        ans.push_back(sub);
      }
    }
    return ans;
  }
};

TEST(test187, SAMPLE1) {
  Solution sol;
}

TEST(test187, SAMPLE2) {
  Solution sol;
}