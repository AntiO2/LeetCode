/**
 * @author Anti
 * @date 2023/10/28
 * @see https://leetcode.cn/problems/maximum-depth-of-binary-tree
 */

#include <queue>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#define null 0
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
TreeNode* make_tree(std::vector<int>& nodes) {
  if (nodes.empty() || nodes[0] == null) {
    return nullptr;
  }
  auto node_iter = nodes.begin();
  auto root = new TreeNode(nodes[0]);
  ++node_iter;
  std::queue<TreeNode*> q;
  q.emplace(root);
  while (!q.empty() && node_iter != nodes.end()) {
    auto curr = q.front();
    q.pop();
    assert(curr);
    if (*node_iter == null) {
      curr->left = nullptr;
    } else {
      auto left_node = new TreeNode(*node_iter);
      curr->left = left_node;
      q.push(left_node);
    }
    ++node_iter;
    if (*node_iter == null) {
      curr->right = nullptr;
    } else {
      auto right_node = new TreeNode(*node_iter);
      curr->right = right_node;
      q.push(right_node);
    }
    ++node_iter;
  }
  return root;
}
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