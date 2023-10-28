/**
 * @author Anti
 * @date 2023/10/28
 * @see https://leetcode.cn/problems/symmetric-tree
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  }
  auto tmp_right = invertTree(root->left);
  root->left = invertTree(root->right);
  root->right = tmp_right;
  return root;
}
bool check_equal(const TreeNode* t1, const TreeNode* t2) {
  auto curr1 = t1, curr2 = t2;
  std::queue<const TreeNode*> q1, q2;
  q1.emplace(t1), q2.emplace(t2);
  while (!q1.empty()) {
    curr1 = q1.front();
    curr2 = q2.front();
    q1.pop();
    q2.pop();
    if (curr1) {
      if (curr2 == nullptr) {
        return false;
      }
      if (curr1->val != curr2->val) {
        return false;
      }
      q1.emplace(curr1->left);
      q1.emplace(curr1->right);
      q2.emplace(curr2->left);
      q2.emplace(curr2->right);
    } else {
      if (curr2 != nullptr) {
        return false;
      }
    }
  }
  return q2.empty();
}
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    auto equal = check_equal(invertTree(root->left), root->right);
    root->left = invertTree(root->left);
    return equal;
  }
};

TEST(test101, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.isSymmetric(make_tree(std::vector{1, 2, 2, 3, 4, 4, 3})), true);
}

TEST(test101, SAMPLE2) {
  Solution sol;
  EXPECT_EQ(sol.isSymmetric(make_tree(std::vector{1, 2, 2, null, 3, null, 3})),
            false);
}