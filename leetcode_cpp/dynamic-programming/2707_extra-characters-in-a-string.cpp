/**
 * @author Anti
 * @date 2024-01-09
 * @see https://leetcode.cn/problems/extra-characters-in-a-string
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <unordered_set>
class Solution {
 public:
  int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
    int n = s.size();
    std::vector<int> d(n + 1, INT_MAX);
    std::unordered_map<std::string, int> mp;
    for (auto s : dictionary) {
      mp[s]++;
    }
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
      d[i] = d[i - 1] + 1;
      for (int j = i - 1; j >= 0; j--) {
        if (mp.count(s.substr(j, i - j))) {
          d[i] = std::min(d[i], d[j]);
        }
      }
    }
    return d[n];
  }
};

TEST(test2707, SAMPLE1) {
  Solution sol;
}

TEST(test2707, SAMPLE2) {
  Solution sol;
}