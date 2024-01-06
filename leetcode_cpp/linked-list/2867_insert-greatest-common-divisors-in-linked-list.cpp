/**
 * @author Anti
 * @date 2024-01-06
 * @see
 * https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include "list.h"
class Solution {
  int gcd(int a, int b) {
    if(b==0) {
      return a;
    }
    return gcd(b,a%b);
  }
 public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    auto curr = head;
    while(curr&&curr->next) {
      auto tmp = new ListNode(gcd(curr->val, curr->next->val), curr->next);
      curr->next = tmp;
      curr = tmp->next;
    }
    return head;
  }
};  // insert-greatest-common-divisors-in-linked-list

TEST(test2867, SAMPLE1) {
  Solution sol;
}

TEST(test2867, SAMPLE2) {
  Solution sol;
}