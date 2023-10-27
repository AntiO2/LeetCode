/**
 * @author Anti
 * @date 2023/10/27
 * @see https://leetcode.cn/problems/swap-nodes-in-pairs
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    auto prev = dummy;
    auto deal = head;  // 当前处理的节点。
    while (deal && deal->next) {
      prev->next = deal->next;
      deal->next = deal->next->next;
      prev->next->next = deal;
      deal = prev->next->next->next;
      prev = prev->next->next;
    }
    auto ans = dummy->next;
    delete dummy;
    return ans;
  }
};

TEST(test24, SAMPLE1) {
  Solution sol;
}

TEST(test24, SAMPLE2) {
  Solution sol;
}