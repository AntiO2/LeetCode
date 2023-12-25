/**
 * @author Anti
 * @date 2023/10/28
 * @see https://leetcode.cn/problems/invert-binary-tree
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    auto tmp_right = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp_right;
    return root;
  }
};

TEST(test226, SAMPLE1) {
  Solution sol;
  auto tree = make_tree(std::vector{4, 2, 7, 1, 3, 6, 9});
  auto ans = make_tree(std::vector{4, 7, 2, 9, 6, 3, 1});
  EXPECT_EQ(equal_tree(sol.invertTree(tree), ans), true);
}

TEST(test226, SAMPLE2) {
  Solution sol;
  auto tree = make_tree(std::vector{2, 1, 3});
  auto ans = make_tree(std::vector{2, 3, 1});
  EXPECT_EQ(equal_tree(sol.invertTree(tree), ans), true);
}

TEST(test226, SAMPLE3) {
  Solution sol;
  auto tree = make_tree(std::vector<int>{});
  auto ans = make_tree(std::vector<int>{});
  EXPECT_EQ(equal_tree(sol.invertTree(tree), ans), true);
}