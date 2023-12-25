/**
 * @author Anti
 * @date 2023/10/24
 * @see https://leetcode.cn/problems/linked-list-cycle
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
  bool hasCycle(ListNode* head) {
    if (head == nullptr) {
      return false;
    }
    auto quick_p = head;
    auto slow_p = head;
    while (quick_p->next && quick_p->next->next) {
      quick_p = quick_p->next->next;
      slow_p = slow_p->next;
      if (slow_p == quick_p) {
        return true;
      }
    }
    return false;
  }
};
TEST(test141, SAMPLE1) {
  Solution sol;
}

TEST(test141, SAMPLE2) {
  Solution sol;
}