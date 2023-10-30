/**
 * @author Anti
 * @date 2023/10/30
 * @see https://leetcode.cn/problems/binary-tree-maximum-path-sum
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  int ans_;
  int postorder_reserve(TreeNode* root) {
    if (!root) {
      return 0;
    }
    auto lpath = postorder_reserve(root->left);
    auto rpath = postorder_reserve(root->right);
    if (lpath < rpath) {
      std::swap(lpath, rpath);
    }
    if (lpath >= 0) {
      if (rpath >= 0) {
        ans_ = std::max(ans_, root->val + lpath + rpath);
      } else {
        ans_ = std::max(ans_, root->val + lpath);
      }
      return root->val + lpath;
    }
    ans_ = std::max(ans_, root->val);
    return root->val;
  }

 public:
  int maxPathSum(TreeNode* root) {
    ans_ = root->val;
    postorder_reserve(root);
    return ans_;
  }
};

TEST(test124, SAMPLE1) {
  Solution sol;
}

TEST(test124, SAMPLE2) {
  Solution sol;

  std::vector nodes{-10, 9, 20, null, null, 15, 7};
  auto root = make_tree(nodes);
  EXPECT_EQ(sol.maxPathSum(root), 42);
}