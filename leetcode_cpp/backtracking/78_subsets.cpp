/**
 * @author Anti
 * @date 2023/11/1
 * @see https://leetcode.cn/problems/subsets
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  void dfs(int step, std::vector<int>& curr, int max_step,
           std::vector<bool>& book, std::vector<std::vector<int>>& ans,
           std::vector<int>& nums, int now) {
    if (step == max_step) {
      return;
    }
    for (int i = now; i < max_step; i++) {
      if (!book[i]) {
        book[i] = true;
        curr[step] = nums[i];
        dfs(step + 1, curr, max_step, book, ans, nums, i);
        ans.emplace_back(curr.begin(), std::next(curr.begin(), step + 1));
        book[i] = false;
      }
    }
  }

 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> ans{std::vector<int>{}};
    std::vector<bool> book(n);
    std::vector<int> curr(n);
    dfs(0, curr, n, book, ans, nums, 0);
    return ans;
  }
};

TEST(test78, SAMPLE1) {
  Solution sol;
  auto n = std::vector{1, 2, 3};
  auto ans = sol.subsets(n);
  bool pause = true;
}

TEST(test78, SAMPLE2) {
  Solution sol;
}