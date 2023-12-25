/**
 * @author Anti
 * @date 2023/10/30
 * @see https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  std::unordered_map<int, int> depth_;
  std::unordered_map<TreeNode*, TreeNode*> father_;
  void dfs(TreeNode* curr, TreeNode* father, int depth) {
    if (curr == nullptr) {
      return;
    }
    father_[curr] = father;
    depth_[curr->val] = depth;
    dfs(curr->left, curr, depth + 1);
    dfs(curr->right, curr, depth + 1);
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, nullptr, 0);
    if (depth_[p->val] > depth_[q->val]) {
      std::swap(p, q);  // 让q的深度更大；
    }
    while (depth_[q->val] > depth_[p->val]) {
      q = father_[q];
    }
    while (q->val != p->val) {
      q = father_[q];
      p = father_[p];
    }
    return q;
  }
};

TEST(test236, SAMPLE1) {
  Solution sol;

}

TEST(test236, SAMPLE2) {
  Solution sol;
}