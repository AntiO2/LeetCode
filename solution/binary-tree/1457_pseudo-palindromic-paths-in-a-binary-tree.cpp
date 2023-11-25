/**
 * @author Anti
 * @date 2023-11-25
 * @see https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <bitset>
#include "anti_binary_tree.h"
class Solution {
 private:
  std::bitset<10> bitset_;
  inline bool check() {
    auto cnt = bitset_.count();
    return cnt==1||cnt==0;
  }
  inline void reverse(int val) {
    if(bitset_.test(val)) {
      bitset_.reset(val);
    } else {
      bitset_.set(val);
    }
  }
  void dfs(TreeNode* curr,int&ans) {
    reverse(curr->val);
    if(curr->left== nullptr&&curr->right== nullptr) {
      ans += int(check());
      reverse(curr->val);
      return ;
    }
    if(curr->left) {
      dfs(curr->left,ans);
    }
    if(curr->right) {
      dfs(curr->right,ans);
    }
    reverse(curr->val);
    return ;
  }
 public:
  int pseudoPalindromicPaths (TreeNode* root) {
    int ans = 0;
    dfs(root,ans);
    return ans;
  }
};  // pseudo-palindromic-paths-in-a-binary-tree

TEST(test1457, SAMPLE1) {
  Solution sol;
}

TEST(test1457, SAMPLE2) {
  Solution sol;
}