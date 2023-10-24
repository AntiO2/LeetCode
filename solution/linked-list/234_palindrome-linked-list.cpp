/**
 * @author Anti
 * @date 2023/10/24
 * @see https://leetcode.cn/problems/palindrome-linked-list
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
 private:
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
  // 1 2 3 4 null 共2n个结点。快指针 1+(2x) < 2n ; x= n-1步。慢指针位置在1 + n - 1 = ns
  // 若共2n+1个结点。比如1 2 3 4 5 null  快指正走n步。位置在2n+1,慢指针位置在1+n,刚好是中心位置。
  ListNode* endOfFirstHalf(ListNode* head) {
    auto slowHead = head;
    auto quickHead = head;
    while (quickHead->next && quickHead->next->next) {
      slowHead = slowHead->next;
      quickHead = quickHead->next->next;
    }
    return slowHead;
  }

 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) {
      return false;
    }
    auto end_of_first_half_list = endOfFirstHalf(head);
    auto reverse_last_half = reverseList(end_of_first_half_list->next);
    bool equal = true;
    auto h1 = head;
    auto h2 = reverse_last_half;
    while (h2) {
      if (h1->val != h2->val) {
        equal = false;
        break;
      }
      h1 = h1->next;
      h2 = h2->next;
    }
    end_of_first_half_list->next = reverseList(reverse_last_half);
    return equal;
  }
};
TEST(test234, SAMPLE1) {
  Solution sol;
}

TEST(test234, SAMPLE2) {
  Solution sol;
}