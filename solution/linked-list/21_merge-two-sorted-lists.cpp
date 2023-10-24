/**
 * @author Anti
 * @date 2023/10/24
 * @see https://leetcode.cn/problems/merge-two-sorted-lists
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 迭代实现
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) {
      return list2;
    }
    if (!list2) {
      return list1;
    }
    ListNode* head = nullptr;
    if (list1->val < list2->val) {
      head = list1;
      list1 = list1->next;
    } else {
      head = list2;
      list2 = list2->next;
    }
    auto curr = head;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        curr = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        curr = list2;
        list2 = list2->next;
      }
    }
    if (!list1) {
      curr->next = list2;
    }
    if (!list2) {
      curr->next = list1;
    }
    return head;
  }
};

/**
 * 通过递归实现
 */
class Solution2 {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) {
      return list2;
    }
    if (!list2) {
      return list1;
    }
    if (list1->val < list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
};

TEST(test21, SAMPLE1) {
  Solution sol;
}

TEST(test21, SAMPLE2) {
  Solution sol;
}