/**
 * @author Anti
 * @date 2023/10/27
 * @see https://leetcode.cn/problems/add-two-numbers
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto val = l1->val + l2->val;
    int c = val / 10 > 0;  // 进位指示器。
    auto head = new ListNode(val % 10);
    auto prev = head;

    while (l1->next && l2->next) {
      val = l1->next->val + l2->next->val + c;
      if (val >= 10) {
        val -= 10;
        c = 1;
      } else {
        c = 0;
      }
      prev->next = new ListNode(val);
      prev = prev->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    if (!l1->next) {
      std::swap(l1, l2);  // 让l1比l2长。
    }
    while (l1->next) {
      val = l1->next->val + c;
      if (val >= 10) {
        val -= 10;
        c = 1;
      } else {
        c = 0;
      }
      prev->next = new ListNode(val);
      prev = prev->next;
      l1 = l1->next;
    }
    if (c) {
      prev->next = new ListNode(1);
    }
    return head;
  }
};

TEST(test2, SAMPLE1) {
  Solution sol;
}

TEST(test2, SAMPLE2) {
  Solution sol;
}