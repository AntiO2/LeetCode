/**
 * @author Anti
 * @date 2023/11/3
 * @see
 * https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include "queue"
#define null -100
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};
Node* make_tree(const std::vector<int>& nodes) {
  if (nodes.empty() || nodes[0] == null) {
    return nullptr;
  }
  auto node_iter = nodes.begin();
  auto root = new Node(nodes[0]);
  ++node_iter;
  std::queue<Node*> q;
  q.emplace(root);
  while (!q.empty() && node_iter != nodes.end()) {
    auto curr = q.front();
    q.pop();
    assert(curr);
    if (*node_iter == null) {
      curr->left = nullptr;
    } else {
      auto left_node = new Node(*node_iter);
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
      auto right_node = new Node(*node_iter);
      curr->right = right_node;
      q.push(right_node);
    }
    ++node_iter;
  }
  return root;
}

bool equal_tree(const Node* t1, const Node* t2) {
  auto curr1 = t1, curr2 = t2;
  std::queue<const Node*> q1, q2;
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

class Solution {
 private:
  void connect_two_node(Node*& prev_node, Node* next_node, Node*& next_level) {
    if (prev_node) {
      prev_node->next = next_node;
    }
    if (!next_level) {
      next_level = next_node;
    }
    prev_node = next_node;
  }

 public:
  Node* connect(Node* root) {
    if (!root) {
      return nullptr;
    }
    auto level_start = root;
    Node *next_level = nullptr, *prev_node = nullptr;
    while (level_start) {
      for (auto iter = level_start; iter; iter = iter->next) {
        if (iter->left) {
          connect_two_node(prev_node, iter->left, next_level);
        }
        if (iter->right) {
          connect_two_node(prev_node, iter->right, next_level);
        }
      }
      level_start = next_level;
      next_level = nullptr;
      prev_node = nullptr;
    }
    return root;
  }
};

TEST(test117, SAMPLE1) {
  Solution sol;
  auto root = make_tree(std::vector{1, 2, 3, 4, 5, null, 7});
  sol.connect(root);
}

TEST(test117, SAMPLE2) {
  Solution sol;
}