// Copyright (c) 2023. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam
// lacinia accumsan. Etiam sed turpis ac ipsum condimentum fringilla. Maecenas
// magna. Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque
// sagittis ligula eget metus. Vestibulum commodo. Ut rhoncus gravida arcu.

/**
 * @author Anti
 * @date 2023/10/27
 * @see https://leetcode.cn/problems/copy-list-with-random-pointer
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return nullptr;
    }
    auto curr = head;
    while (curr) {
      auto new_node = new Node(curr->val);
      new_node->next = curr->next;
      curr->next = new_node;
      curr = new_node->next;
    }
    curr = head;
    while (curr) {
      if (curr->random) {
        curr->next->random = curr->random->next;
      } else {
        curr->next->random = nullptr;
      }
      curr = curr->next->next;
    }
    auto ans_head = head->next;
    curr = head;
    auto ans_curr = ans_head;
    auto tmp_next_group = ans_curr->next;
    while (tmp_next_group) {
      curr->next = tmp_next_group;
      ans_curr->next = tmp_next_group->next;
      curr = tmp_next_group;
      ans_curr = ans_curr->next;
      tmp_next_group = ans_curr->next;
    }
    curr->next = nullptr;
    return ans_head;
  }
};

TEST(test138, SAMPLE1) {
  Solution sol;
}

TEST(test138, SAMPLE2) {
  Solution sol;
}