/**
 * @author Anti
 * @date 2023/10/28
 * @see https://leetcode.cn/problems/binary-tree-inorder-traversal
 */

#include <stack>
#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> nodes;
    std::vector<int> ans;
    while (root || !nodes.empty()) {
      while (root != nullptr) {
        nodes.emplace(root);
        root = root->left;
      }
      root = nodes.top();
      nodes.pop();
      ans.emplace_back(root->val);  //
      root = root->right;
    }
    return ans;
  }
};

TEST(test94, SAMPLE1) {
  Solution sol;
  auto root =
      new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
  std::vector<int> ans{1, 3, 2};
  EXPECT_EQ(sol.inorderTraversal(root), ans);
}

TEST(test94, SAMPLE2) {
  Solution sol;
}