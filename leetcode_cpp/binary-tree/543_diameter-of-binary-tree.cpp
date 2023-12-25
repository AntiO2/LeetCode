/**
 * @author Anti
 * @date 2023/10/28
 * @see https://leetcode.cn/problems/diameter-of-binary-tree
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  int max_diameter = 0;

 public:
  int diameterOfBinaryTree(TreeNode* root) {
    postorder(root);
    return max_diameter;
  }

 private:
  /**
   * 后序遍历，并更新直径最大值
   * @param root 该直径必须通过root
   * @return
   */
  int postorder(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    auto l_max = postorder(root->left);
    auto r_max = postorder(root->right);
    max_diameter = std::max(max_diameter, l_max + r_max);
    return std::max(l_max, r_max) + 1;
  }
};

TEST(test543, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.diameterOfBinaryTree(make_tree(std::vector{1, 2, 3, 4, 5})), 3);
}

TEST(test543, SAMPLE2) {
  Solution sol;
  EXPECT_EQ(sol.diameterOfBinaryTree(make_tree(std::vector{1, 2})), 1);
}