/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/partition-labels
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  inline int get_index(char c) { return c - 'a'; }

 public:
  std::vector<int> partitionLabels(std::string s) {
    std::vector<int> end(26);  // 每个字母结束的位置
    std::vector<int> ans;
    for (int i = 0; i < s.length(); i++) {
      end[get_index(s[i])] = i;
    }
    int start = 0, curr_end = 0;
    for (int i = 0; i < s.length(); i++) {
      curr_end = std::max(curr_end, end[get_index(s[i])]);
      if (i == curr_end) {
        ans.push_back(curr_end - start + 1);
        start = curr_end + 1;
      }
    }
    return ans;
  }
};

TEST(test763, SAMPLE1) {
  Solution sol;
}

TEST(test763, SAMPLE2) {
  Solution sol;
}