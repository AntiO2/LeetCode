/**
 * @author Anti
 * @date 2023-12-05
 * @see https://leetcode.cn/problems/odd-even-linked-list
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include "list.h"
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if(!head) {
      return nullptr;
    }
    bool odd = false;
    auto evenhead = new ListNode(-1);
    auto even = evenhead;
    auto dummy = new ListNode(-1,head);
    auto prev = dummy;
    while(head) {
      odd^= true;
      if(!odd) {
        prev->next = head->next;
        even->next = head;
        even = head;
        even->next = nullptr;
        head = prev->next;
      } else {
        prev = head;
        head = head->next;
      }
    }
    prev->next = evenhead->next;
    delete evenhead;
    auto tmp = dummy->next;
    delete dummy;
    return tmp;
  }
}; // odd-even-linked-list

TEST(test328, SAMPLE1) {
  Solution sol;
  std::vector a{1,2,3,4,5};
  auto l = new List(a);
  auto ans = new List(std::vector{1,3,5,2,4});
  EXPECT_EQ(sol.oddEvenList(l->get_head()), ans->get_head());
  delete l;
}

TEST(test328, SAMPLE2) {
  Solution sol;
}