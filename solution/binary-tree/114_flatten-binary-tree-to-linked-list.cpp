/**
 * @author Anti
 * @date 2023/10/29
 * @see https://leetcode.cn/problems/flatten-binary-tree-to-linked-list
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  // 以curr为根，返回链表尾结点。
  TreeNode* sub_flat(TreeNode* curr) {
    if (curr == nullptr) {
      return nullptr;
    }
    if (curr->left == nullptr) {
      if (curr->right) {
        return sub_flat(curr->right);
      }
      return curr;
    }
    // 左子树不为空
    auto curr_tail = curr;
    if (curr->right) {
      curr_tail = sub_flat(curr->right);
    }
    auto tmp = sub_flat(curr->left);
    if (!curr->right) {
      curr_tail = tmp;
    }
    tmp->right = curr->right;
    curr->right = curr->left;
    curr->left = nullptr;
    return curr_tail;
  }

 public:
  void flatten(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    sub_flat(root);
  }
};

TEST(test114, SAMPLE1) {
  Solution sol;
  auto t = make_tree(std::vector{1, 2, 5, 3, 4, null, 6});
  sol.flatten(t);
}

TEST(test114, SAMPLE2) {
  Solution sol;
  auto t = make_tree(std::vector{1, 2, null, 3});
  sol.flatten(t);
}