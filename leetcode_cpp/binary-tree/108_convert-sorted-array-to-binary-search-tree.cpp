/**
 * @author Anti
 * @date 2023/10/28
 * @see https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    int l = 0;
    int r = nums.size();
    return make_sub_bst(nums, l, r);
  }

 private:
  TreeNode* make_sub_bst(std::vector<int>& nums, int first, int last) {
    if (first > last) {
      return nullptr;
    }
    auto mid = (first + last) / 2;
    if (mid >= nums.size()) {
      return nullptr;
    }
    auto sub_root = new TreeNode(nums[mid]);
    sub_root->left = make_sub_bst(nums, first, mid - 1);
    sub_root->right = make_sub_bst(nums, mid + 1, last);
    return sub_root;
  }
};

TEST(test108, SAMPLE1) {
  Solution sol;
}

TEST(test108, SAMPLE2) {
  Solution sol;
}