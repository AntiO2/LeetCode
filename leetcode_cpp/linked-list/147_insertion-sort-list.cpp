/**
 * @author Anti
 * @date 2024-01-25
 * @see https://leetcode.cn/problems/insertion-sort-list
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include "list.h"

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    auto dummy = std::make_unique<ListNode>(0,head);
    auto curr = head;
    auto last_ordered = curr;
    curr = curr->next;
    while (curr) {
      if(curr->val>=last_ordered->val) {
        last_ordered = curr;
        curr = curr->next;
        continue ;
      }
      auto &val = curr->val;
      auto begin = dummy->next;
      auto prev = dummy.get();
      while(begin!=curr) {
        if(begin->val >= val) {
          last_ordered->next = curr->next;
          curr->next = begin;
          prev->next = curr;
          break ;
        }
        begin = begin->next;
        prev = prev->next;
      }
      curr = last_ordered->next;
    }
    return dummy->next;
  }
}; // insertion-sort-list

TEST(test147, SAMPLE1) {
  Solution sol;
  List l(std::vector<int>{4,2,1,3});
  sol.insertionSortList(l.get_head());
}

TEST(test147, SAMPLE2) {
  Solution sol;
}