# 二叉树测试

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

这里暂时将`null` 定义为了0

参考[104_maximum-depth-of-binary-tree](./104_maximum-depth-of-binary-tree.cpp)的测试是如何使用的。
