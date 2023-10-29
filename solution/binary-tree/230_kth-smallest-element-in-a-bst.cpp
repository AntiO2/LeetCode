/**
 * @author Anti
 * @date 2023/10/29
 * @see https://leetcode.cn/problems/kth-smallest-element-in-a-bst
 */

#include <stack/>
#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> stack;
    while (root != nullptr || stack.size() > 0) {
      while (root != nullptr) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top();
      stack.pop();
      --k;
      if (k == 0) {
        break;
      }
      root = root->right;
    }
    return root->val;
  }
};
TEST(test230, SAMPLE1) {
  Solution sol;
}

TEST(test230, SAMPLE2) {
  Solution sol;
}