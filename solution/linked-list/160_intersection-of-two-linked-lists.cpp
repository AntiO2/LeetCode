/**
 * @author Anti
 * @date 2023/10/23
 * @see https://leetcode.cn/problems/intersection-of-two-linked-lists
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    auto ap = headA, bp = headB;
    while (ap != bp) {
      ap = ap == nullptr ? headB : ap->next;
      bp = bp == nullptr ? headA : bp->next;
    }
    return ap;
  }
};

TEST(test160, SAMPLE1) {
  Solution sol;
}

TEST(test160, SAMPLE2) {
  Solution sol;
}