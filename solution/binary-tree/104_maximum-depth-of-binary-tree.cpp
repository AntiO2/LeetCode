/**
 * @author Anti
 * @date 2023/10/28
 * @see https://leetcode.cn/problems/maximum-depth-of-binary-tree
 */

#include <queue>
#include "anti_binary_tree.h"
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int max_depth = 0;
    std::queue<std::pair<TreeNode*, int>> bfs;  // BFS遍历。
    bfs.emplace(root, 1);
    while (!bfs.empty()) {
      auto node_info = bfs.front();
      bfs.pop();
      auto depth = node_info.second;
      auto node = node_info.first;
      max_depth = std::max(max_depth, depth);
      if (node->left) {
        bfs.emplace(node->left, depth + 1);
      }
      if (node->right) {
        bfs.emplace(node->right, depth + 1);
      }
    }
    return max_depth;
  }
};
TEST(test104, SAMPLE1) {
  std::vector<int> nodes{1, null, 2};
  auto root = make_tree(nodes);
  Solution sol;
  EXPECT_EQ(sol.maxDepth(root), 2);
  delete root;
}

TEST(test104, SAMPLE2) {
  std::vector<int> nodes{3, 9, 20, null, null, 15, 7};
  auto root = make_tree(nodes);
  Solution sol;
  EXPECT_EQ(sol.maxDepth(root), 3);
}