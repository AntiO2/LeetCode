/**
 * @author Anti
 * @date 2023-12-15
 * @see https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* reverseOddLevels(TreeNode* root) {

    std::function<void(TreeNode*,TreeNode*, int)> dfs = [&](TreeNode* curr1,TreeNode* curr2,int depth) -> void {
      if(curr1==nullptr) {
        return;
      }
      if(depth%2) {
        // 奇数层
        std::swap(curr1->val, curr2->val);
      }
      dfs(curr1->left, curr2->right, depth+1);
      dfs(curr1->right, curr2->left, depth+1);
    };
    dfs(root->left, root->right, 1);
    return root;
  }
}; // reverse-odd-levels-of-binary-tree

TEST(test2415, SAMPLE1) {
  Solution sol;
}

TEST(test2415, SAMPLE2) {
  Solution sol;
}