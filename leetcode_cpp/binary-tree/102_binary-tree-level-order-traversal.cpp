/**
 * @author Anti
 * @date 2023/10/28
 * @see https://leetcode.cn/problems/binary-tree-level-order-traversal
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    std::queue<TreeNode*> q1;
    std::queue<TreeNode*> q2;
    std::vector<std::vector<int>> ans;

    auto level_now = &q1;
    auto level_next = &q2;
    level_now->emplace(root);
    do {
      std::vector<int> lev;
      while (!level_now->empty()) {
        auto node = level_now->front();
        level_now->pop();
        lev.emplace_back(node->val);
        if (node->left) {
          level_next->emplace(node->left);
        }
        if (node->right) {
          level_next->emplace(node->right);
        }
      }
      // 这一层次遍历完。
      std::swap(level_next, level_now);
      ans.emplace_back(std::move(lev));
    } while (!level_now->empty());
    return ans;
  }
};

TEST(test102, SAMPLE1) {
  Solution sol;
  sol.levelOrder(make_tree(std::vector{3, 9, 20, null, null, 15, 7}));
}

TEST(test102, SAMPLE2) {
  Solution sol;
}