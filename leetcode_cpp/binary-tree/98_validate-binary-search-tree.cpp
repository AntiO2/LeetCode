/**
 * @author Anti
 * @date 2023/10/29
 * @see https://leetcode.cn/problems/validate-binary-search-tree
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  bool validate_sub_bst(TreeNode* root, int& max, int& min) {
    assert(root);
    int maxv = root->val, minv = root->val;
    if (root->left) {
      int lmax = 0, lmin = 0;
      if (!validate_sub_bst(root->left, lmax, lmin)) {
        return false;
      }
      if (root->val <= lmax) {
        return false;
      }
      minv = std::min(minv, lmin);
    }
    if (root->right) {
      int rmax = 0, rmin = 0;
      if (!validate_sub_bst(root->right, rmax, rmin)) {
        return false;
      }
      if (root->val >= rmin) {
        return false;
      }
      maxv = std::max(maxv, rmax);
    }
    max = maxv;
    min = minv;
    return true;
  }

 public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    int max = root->val;
    int min = root->val;
    return validate_sub_bst(root, max, min);
  }
};

TEST(test98, SAMPLE1) {
  Solution sol;
  auto t = make_tree(std::vector{2, 1, 3});
  EXPECT_EQ(sol.isValidBST(t), true);
}

TEST(test98, SAMPLE2) {
  Solution sol;
  auto t = make_tree(std::vector{5, 1, 4, null, null, 3, 6});
  EXPECT_EQ(sol.isValidBST(t), false);
}

TEST(test98, SAMPLE3) {
  Solution sol;
  auto t = make_tree(std::vector{2, 2, 2});
  EXPECT_EQ(sol.isValidBST(t), false);
}

TEST(test98, SAMPLE4) {
  Solution sol;
  auto t = make_tree(std::vector{32, 26, 47, 19, null, null, 56, null, 27});
  EXPECT_EQ(sol.isValidBST(t), false);
}