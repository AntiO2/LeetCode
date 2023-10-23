/**
 * @author Anti
 * @date 2023/10/23
 * @see https://leetcode.cn/problems/reverse-linked-list
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
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
      auto tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    return prev;
  }
};
TEST(test206, SAMPLE1) {
  Solution sol;
}

TEST(test206, SAMPLE2) {
  Solution sol;
}