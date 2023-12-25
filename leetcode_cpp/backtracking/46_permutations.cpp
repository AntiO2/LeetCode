/**
 * @author Anti
 * @date 2023/11/1
 * @see https://leetcode.cn/problems/permutations
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  void dfs(int step, std::vector<int>& curr, int max_step,
           std::vector<bool>& book, std::vector<std::vector<int>>& ans,
           std::vector<int>& nums) {
    if (step == max_step) {
      ans.emplace_back(curr.begin(), curr.end());
      return;
    }
    for (int i = 0; i < max_step; i++) {
      if (!book[i]) {
        book[i] = true;
        curr[step] = nums[i];
        dfs(step + 1, curr, max_step, book, ans, nums);
        book[i] = false;
      }
    }
  }

 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<bool> book(n);
    std::vector<std::vector<int>> ans;
    std::vector<int> curr(n);
    dfs(0, curr, n, book, ans, nums);
    return ans;
  }
};

TEST(test46, SAMPLE1) {
  Solution sol;
  std::vector n{0, 1, 2};
  auto ans = sol.permute(n);
}

TEST(test46, SAMPLE2) {
  Solution sol;
}