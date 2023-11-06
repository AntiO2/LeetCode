/**
 * @author Anti
 * @date 2023/11/6
 * @see https://leetcode.cn/problems/maximum-product-of-word-lengths
 */

#include <bitset>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  using word_map = std::bitset<26>;

 public:
  int maxProduct(std::vector<std::string>& words) {
    std::unordered_map<word_map, int> cnt_length;  // 最长的length.
    for (const auto& word : words) {
      word_map w;
      for (const auto& c : word) {`
        w.set(c - 'a', true);
      }
      auto l = word.length();
      auto iter = cnt_length.find(w);
      if (iter != cnt_length.end() && iter->second > l) {
        l = iter->second;
      }
      cnt_length[w] = l;
    }
    std::vector<std::pair<word_map, int>> result;
    result.reserve(cnt_length.size());
    for (auto& cnt : cnt_length) {
      result.emplace_back(cnt);
    }
    auto l = cnt_length.size();
    int ans = 0;
    for (int i = 0; i < l; ++i) {
      for (int j = i + 1; j < l; ++j) {
        if (!(result[i].first & result[j].first).any()) {
          ans = std::max(ans, result[i].second * result[j].second);
        }
      }
    }
    return ans;
  }
};

TEST(test318, SAMPLE1) {
  Solution sol;
  std::vector<std::string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  EXPECT_EQ(sol.maxProduct(words), 16);
}

TEST(test318, SAMPLE2) {
  Solution sol;
}