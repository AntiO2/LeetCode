/**
 * @author Anti
 * @date 2023/10/31
 * @see
 * https://leetcode.cn/problems/smallest-missing-genetic-value-in-each-subtree
 */

#include <list>
#include <unordered_set>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  std::unordered_map<int, std::list<int>> children;
  std::unordered_set<int> genes_;  // 出现过的基因。
  void search(int curr, std::vector<int>& nums) {
    if (genes_.count(nums[curr])) {
      return;
    }
    genes_.emplace(nums[curr]);
    auto child_list = children.find(curr);
    if (child_list == children.end()) {
      return;
    }
    for (auto& child : (*child_list).second) {
      search(child, nums);
    }
  }

 public:
  std::vector<int> smallestMissingValueSubtree(std::vector<int>& parents,
                                               std::vector<int>& nums) {
    auto n = parents.size();
    std::vector<int> ans(parents.size(), 1);

    int curr = -1;
    int min_gene = 1;  // 当前出现过的最小基因
    for (auto i = 0; i < n; i++) {
      children[parents[i]].emplace_back(i);
      if (nums[i] == 1) {
        curr = i;  // 从当前结点从下网上找。
      }
    }
    while (curr != -1) {
      search(curr, nums);
      while (true) {
        if (!genes_.contains(min_gene)) {
          break;
        }
        ++min_gene;
      }
      ans[curr] = min_gene;
      curr = parents[curr];
    }
    return ans;
  }
};

TEST(test2003, SAMPLE1) {
  Solution sol;
  std::vector parents{-1, 0, 0, 2};
  std::vector nums{1, 2, 3, 4};
  std::vector ans{5, 1, 1, 1};
  EXPECT_EQ(sol.smallestMissingValueSubtree(parents, nums), ans);
}

TEST(test2003, SAMPLE2) {
  Solution sol;
  std::vector parents{-1, 0, 1, 0, 3, 3};
  std::vector nums{5, 4, 6, 2, 1, 3};
  std::vector ans{7, 1, 1, 4, 2, 1};
  EXPECT_EQ(sol.smallestMissingValueSubtree(parents, nums), ans);
}