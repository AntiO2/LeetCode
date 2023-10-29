/**
 * @author Anti
 * @date 2023/10/29
 * @see
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  TreeNode* buildSubTree(std::vector<int>& preorder, std::vector<int>& inorder,
                         int inorder_first, int preorder_first, int len) {
    if (len <= 0) {
      return nullptr;
    }
    auto root_val = preorder.at(preorder_first);
    auto root_node = new TreeNode(root_val);
    int i = 0;
    for (; i < len; i++) {
      // 找到中序遍历的位置
      if (inorder[inorder_first + i] == root_val) {
        break;
      }
    }
    root_node->left =
        buildSubTree(preorder, inorder, inorder_first, preorder_first + 1, i);
    root_node->right = buildSubTree(preorder, inorder, inorder_first + 1 + i,
                                    preorder_first + 1 + i, len - i - 1);
    return root_node;
  }

 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return buildSubTree(preorder, inorder, 0, 0, preorder.size());
  }
};

TEST(test105, SAMPLE1) {
  Solution sol;
  std::vector pre{3, 9, 20, 15, 7};
  std::vector in{9, 3, 15, 20, 7};
  auto ans = make_tree(std::vector{3, 9, 20, null, null, 15, 7});
  auto build_tree = sol.buildTree(pre, in);
  EXPECT_EQ(equal_tree(ans, build_tree), true);
}

TEST(test105, SAMPLE2) {
  Solution sol;
}