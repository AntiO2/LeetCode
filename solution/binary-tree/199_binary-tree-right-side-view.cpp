/**
 * @author Anti
 * @date 2023/10/29
 * @see https://leetcode.cn/problems/binary-tree-right-side-view
 */

#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  std::unordered_map<int, int> view;
  void search_tree(TreeNode* curr, int depth) {
    if (!curr) {
      return;
    }
    search_tree(curr->left, depth + 1);
    view[depth] = curr->val;
    search_tree(curr->right, depth + 1);
  }

 public:
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> ans{};
    if (!root) {
      return ans;
    }
    search_tree(root, 0);
    ans.reserve(view.size());
    std::map<int, int> orderedMap(view.begin(), view.end());
    for (auto& v : orderedMap) {
      ans.emplace_back(v.second);
    }
    return ans;
  }
};
TEST(test199, SAMPLE1) {
  Solution sol;
}

TEST(test199, SAMPLE2) {
  Solution sol;
}