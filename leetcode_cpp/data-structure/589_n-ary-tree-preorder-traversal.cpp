/**
 * @author Anti
 * @date 2024-02-18
 * @see https://leetcode.cn/problems/n-ary-tree-preorder-traversal
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};
class Solution {
 public:
  std::vector<int> preorder(Node* root) {
    std::vector<int> ans;
    std::function<void(Node*)>func = [&](Node* curr) -> void {
      if(!curr) {
        return ;
      }
      ans.emplace_back(curr->val);
      for(const auto&child:curr->children) {
        func(child);
      }
    };
    func(root);
    return ans;
  }
};