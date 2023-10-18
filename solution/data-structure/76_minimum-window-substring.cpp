//
// Created by Anti on 2023/10/18.
//
#include <algorithm>
#include <deque>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  struct sub_info {
    sub_info(size_t p, char cc) : pos(p), c(cc) {}
    size_t pos;
    char c;
  };

 public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> count_t;  //统计t中的字符数量
    std::unordered_map<char, int> count_s;  // 统计s中字符串的数量
    std::vector<std::pair<int, int>> possible_ans;  // 子串
    std::deque<sub_info> curr_sub;                  // 当前的子串
    size_t match_num = 0;                           //已匹配的字符

    for (auto& c : t) {
      ++count_t[c];
    }
    size_t target_match = count_t.size();
    int s_len = int(s.length());
    for (int i = 0; i < s_len; ++i) {
      auto iter = count_t.find(s[i]);
      if (iter == count_t.end()) {
        // 与结果无关
        continue;
      }
      ++count_s[s[i]];
      if (count_s[s[i]] == count_t[s[i]]) {
        ++match_num;
      }
      while (!curr_sub.empty()) {
        if (count_s[curr_sub.front().c] > count_t[curr_sub.front().c]) {
          --count_s[curr_sub.front().c];
          curr_sub.pop_front();
        } else {
          break;
        }
      }
      curr_sub.emplace_back(i, s[i]);
      if (match_num == target_match) {
        possible_ans.emplace_back(curr_sub.front().pos, i);
      }
    }
    std::ranges::sort(possible_ans, [](const std::pair<int, int>& a,
                                       const std::pair<int, int>& b) {
      return a.second - a.first < b.second - b.first;
    });
    return possible_ans.empty() ? ""
                                : s.substr(possible_ans.at(0).first,
                                           possible_ans.at(0).second -
                                               possible_ans.at(0).first + 1);
  }
};

TEST(test76, SAMPLE1) {
  Solution sol;
  std::string s = "ADOBECODEBANC";
  std::string t = "ABC";
  std::string ans = "BANC";
  EXPECT_EQ(sol.minWindow(s, t), ans);
  // LOG_INFO("SAMPLE1 PASS");
}

TEST(test76, SAMPLE2) {
  Solution sol;
  std::string s = "a";
  std::string t = "a";
  std::string ans = "a";
  EXPECT_EQ(sol.minWindow(s, t), ans);
  // LOG_INFO("SAMPLE2 PASS");
}

TEST(test76, SAMPLE3) {
  Solution sol;
  std::string s = "a";
  std::string t = "aa";
  std::string ans = "";
  EXPECT_EQ(sol.minWindow(s, t), ans);
}
