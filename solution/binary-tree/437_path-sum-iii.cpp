/**
 * @author Anti
 * @date 2023/10/30
 * @see https://leetcode.cn/problems/path-sum-iii
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  std::unordered_map<long long, int> prefix_sum_counter_{};
  int dfs(TreeNode* curr, int target, long long prefix_sum) {
    if (!curr) {
      return 0;
    }
    int ans = prefix_sum_counter_[curr->val + prefix_sum - target];
    // LOG_INFO("%s",
    //          fmt::format("node{} prefix:{}", curr->val, prefix_sum).c_str());
    prefix_sum_counter_[prefix_sum + curr->val]++;
    ans += dfs(curr->left, target, prefix_sum + curr->val);
    ans += dfs(curr->right, target, prefix_sum + curr->val);
    prefix_sum_counter_[prefix_sum + curr->val]--;
    return ans;
  }

 public:
  int pathSum(TreeNode* root, int targetSum) {
    prefix_sum_counter_[0] = 1;
    return dfs(root, targetSum, 0);
  }
};

TEST(test437, SAMPLE1) {
  Solution sol;
  auto root = make_tree(std::vector{10, 5, -3, 3, 2, null, 11, 3, -2, null, 1});
  EXPECT_EQ(sol.pathSum(root, 8), 3);
}

TEST(test437, SAMPLE2) {
  Solution sol;
}