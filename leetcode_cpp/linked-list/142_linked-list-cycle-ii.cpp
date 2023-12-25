/**
 * @author Anti
 * @date 2023/10/24
 * @see https://leetcode.cn/problems/linked-list-cycle-ii
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
  ListNode* detectCycle(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    auto p1 = head, p2 = head;
    bool has_cycle = false;
    while (p2->next && p2->next->next) {
      // 首先判断是否有环。
      p2 = p2->next->next;
      p1 = p1->next;
      if (p1 == p2) {
        has_cycle = true;
        break;
      }
    }
    if (!has_cycle) {
      return nullptr;
    }
    p2 = head;
    while (p2 != p1) {
      p1 = p1->next;
      p2 = p2->next;
    }
    return p1;
  }
};

TEST(test142, SAMPLE1) {
  Solution sol;
}

TEST(test142, SAMPLE2) {
  Solution sol;
}