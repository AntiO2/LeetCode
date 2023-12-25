//
// Created by Anti on 2023/10/28.
//
#include <compare>
template <typename T>
struct TreeNode {
  T val;
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  TreeNode() : left(nullptr), right(nullptr) {}
  TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(T x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
template <typename T>
struct SearchTree {
 private:
  TreeNode<T>* root_;
  /**
   * 让v代替u的位置
   * @param u
   * @param v
   */
  void transplant(TreeNode<T>* u, TreeNode<T>* v) {
    if (u->parent == nullptr) {
      // u本来是根节点的情况。
      root_ = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    if (v != nullptr) {
      v->parent = u;
    }
  }

 public:
  TreeNode<T>* min_of_tree(TreeNode<T>* n) {
    if (n == nullptr) {
      return nullptr;
    }
    while (n->left != nullptr) {
      n = n->left;
    }
    return n;
  }
  void delete_node(TreeNode<T>* n) {
    if (n == nullptr) {
      return;
    }
    if (n->left == nullptr) {
      transplant(n, n->right);  // 这里有两种情况：
      // 1. n.right 为nullptr
      // 2. n.right不为nullptr。实际上是一样的，
    } else {
      if (n->right == nullptr) {
        transplant(n, n->left);
      } else {
        auto y = min_of_tree(n->right);  // 找到后继结点。
        if (y->parent != n) {
          // 感觉这里不判断也行，没有影响。
          transplant(y, y->right);
          y->right = n->right;
          y->right->parent = y;
        }
        transplant(n, y);
        y->left = n->left;
        y->left->parent = y;
      }
    }
  }
  /**
   *
   * @param t 要插入的新值
   */
  void insert(T t) requires std::totally_ordered<T> {
    auto* node = new TreeNode(t);  // 要插入的新结点
    TreeNode<T>* y = nullptr;
    TreeNode<T>* x = root_;  // x是node应当插入的位置。
    while (x != nullptr) {
      y = x;
      if (x->val < t) {
        x = x->right;
      } else {
        x = x->left;
      }
    }
    node->parent = y;
    if (node->val < y->val) {
      y->left = node;
    } else {
      y->right = node;
    }
  }
};

template class TreeNode<int>;
template class SearchTree<int>;