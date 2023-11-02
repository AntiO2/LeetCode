/**
 * @author Anti
 * @date 2023/11/2
 * @see https://leetcode.cn/problems/combination-sum
 */

#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  /**
   *
   * @param prev 之前的和
   * @param candidates 候选数字
   * @param ans 答案
   * @param pos 当前数字的位置
   * @param target 目标和
   * @param nums 目前选中的数字
   * @return
   */
  bool dfs(int prev, std::vector<int>& candidates,
           std::vector<std::vector<int>>& ans, int pos, int target,
           std::list<int>& nums) {
    if (pos >= candidates.size()) {
      return false;
    }

    if (prev > target) {
      return false;  // 立即停止遍历（剪枝）
    }
    if (prev == target) {
      ans.emplace_back(nums.begin(), nums.end());
      return true;
    }
    for (int i = pos; i < candidates.size(); ++i) {
      nums.emplace_back(candidates[i]);
      if (!dfs(prev+candidates[i], candidates, ans, i, target, nums)) {
        nums.pop_back();
        break;
      }
      nums.pop_back();
    }
    return true;
  }

 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target) {
  std:
    sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ans;
    std::list<int> nums;
    dfs(0, candidates, ans, 0, target, nums);
    return ans;
  }
};

TEST(test39, SAMPLE1) {
  Solution sol;
  std::vector c{2, 3, 6, 7};
  auto target = 7;
  auto ans = sol.combinationSum(c, target);
  bool pause;
}

TEST(test39, SAMPLE2) {
  Solution sol;
}