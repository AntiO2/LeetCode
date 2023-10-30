# 二叉树测试

模板定义在[anti_binary_tree](./anti_binary_tree.h) 中

## 创建二叉树

[请问[1, null, 2, 3] 在二叉树测试用例中代表什么 - 力扣（LeetCode） - 支持](https://support.leetcode.cn/hc/kb/article/1549360/)

通过数组创建二叉树。

```c++
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
```

这里暂时将`null` 定义为了`INT_MIN`。

参考[104_maximum-depth-of-binary-tree](./104_maximum-depth-of-binary-tree.cpp)的测试是如何创建二叉树的。

## 判断二叉树相等

这里判断结构以及值是否相等，不判断是否是同一个节点。

使用参考[226_invert-binary-tree](./226_invert-binary-tree.cpp)中的测试用例。

```C++
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
```
