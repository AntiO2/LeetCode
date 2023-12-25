/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/top-k-frequent-element
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> cnt_freq{};
    std::set<int> s;
    for (auto num : nums) {
      cnt_freq[num]++;
      s.emplace(num);
    }
    std::vector<int> tmp(s.begin(), s.end());
    std::partial_sort(tmp.begin(), tmp.begin() + k, tmp.end(),
                      [&cnt_freq](const auto& a, const auto& b) {
                        return cnt_freq[a] > cnt_freq[b];
                      });
    return std::vector(tmp.begin(), tmp.begin() + k);
  }
};
TEST(test347, SAMPLE1) {
  Solution sol;
  std::vector nums{1, 1, 1, 2, 2, 3};
  int k = 2;
  sol.topKFrequent(nums, k);
}

TEST(test347, SAMPLE2) {
  Solution sol;
}