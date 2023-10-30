//
// Created by Anti on 2023/10/28.
//

#ifndef ANTI_BINARY_TREE_H
#define ANTI_BINARY_TREE_H
#include <cassert>
#include <climits>
#include <queue>
#include <vector>
#define null INT_MIN
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
TreeNode* make_tree(const std::vector<int>& nodes) {
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
    if (node_iter == nodes.end()) {
      break;
    }
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

bool equal_tree(const TreeNode* t1, const TreeNode* t2) {
  auto curr1 = t1, curr2 = t2;
  std::queue<const TreeNode*> q1, q2;
  q1.emplace(t1), q2.emplace(t2);
  while (!q1.empty()) {
    curr1 = q1.front();
    curr2 = q2.front();
    q1.pop();
    q2.pop();
    if (curr1) {
      if (curr2 == nullptr) {
        return false;
      }
      if (curr1->val != curr2->val) {
        return false;
      }
      q1.emplace(curr1->left);
      q1.emplace(curr1->right);
      q2.emplace(curr2->left);
      q2.emplace(curr2->right);
    } else {
      if (curr2 != nullptr) {
        return false;
      }
    }
  }
  return q2.empty();
}
#endif  // ANTI_BINARY_TREE_H
