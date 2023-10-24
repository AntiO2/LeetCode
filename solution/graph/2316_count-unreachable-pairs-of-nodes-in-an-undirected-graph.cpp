/**
 * @author Anti
 * @date 2023/10/21
 * @see
 * https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
 */

#include <numeric>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  std::vector<int> father_;
  auto join(int a, int b) -> void { father_[find(b)] = find(a); }
  auto find(int a) -> int {
    return father_[a] == a ? a : father_[a] = find(father_[a]);
  }

 public:
  long long countPairs(int n, std::vector<std::vector<int>>& edges) {
    father_.resize(n);
    std::iota(father_.begin(), father_.end(), 0);
    for (auto& edge : edges) {
      join(edge[0], edge[1]);
    }
    std::unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
      count[find(i)]++;
    }
    long long prev = 0;
    long long ans = 0;
    for (auto count_result : count) {
      ans += prev * count_result.second;
      prev += count_result.second;
    }
    return ans;
  }
};

TEST(test2316, SAMPLE1) {
  Solution sol;
}

TEST(test2316, SAMPLE2) {
  Solution sol;
}