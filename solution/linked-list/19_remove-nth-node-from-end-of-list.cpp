/**
 * @author Anti
 * @date 2023/10/27
 * @see https://leetcode.cn/problems/remove-nth-node-from-end-of-list
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* quick = head;
    ListNode* slow = dummy;
    for (int i = 1; i <= n; i++) {
      quick = quick->next;
    }
    while (quick) {
      slow = slow->next;
      quick = quick->next;
    }
    slow->next = slow->next->next;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
  }
};

TEST(test19, SAMPLE1) {
  Solution sol;
}

TEST(test19, SAMPLE2) {
  Solution sol;
}