// Copyright (c) 2023. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam
// lacinia accumsan. Etiam sed turpis ac ipsum condimentum fringilla. Maecenas
// magna. Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque
// sagittis ligula eget metus. Vestibulum commodo. Ut rhoncus gravida arcu.

/**
 * @author Anti
 * @date 2023/10/27
 * @see https://leetcode.cn/problems/reverse-nodes-in-k-group
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
template <typename T>
struct ListNodeTemp {
  T val;
  ListNodeTemp* next;
  explicit ListNodeTemp(T x) : val(x), next(nullptr) {}
  ListNodeTemp(T x, ListNodeTemp* next) : val(x), next(next) {}
};
template <typename T>
struct List {
  ListNodeTemp<T>* dummy;  // 虚拟头节点。
  ListNodeTemp<T>* last;
  List() {
    dummy = new ListNodeTemp(0);
    last = dummy;
  }
  explicit List(std::vector<T> args) {
    dummy = new ListNodeTemp(0);
    last = dummy;
    std::for_each(args.begin(), args.end(), [&](T t) { push_back(t); });
  }
  ~List() {
    while (dummy != last) {
      auto tmp = dummy;
      dummy = dummy->next;
      delete tmp;
    }
    delete dummy;
  }

  inline auto get_head() -> ListNodeTemp<T>* { return dummy->next; }
  inline void push_back(ListNodeTemp<T>* x) {
    last->next = x;
    last = x;
  }

  void push_back(T val) {
    auto x = new ListNodeTemp(val);
    push_back(x);
  }
};
template class ListNodeTemp<int>;
using ListNode = ListNodeTemp<int>;

/**
 * 值判断
 * @tparam T
 * @param h1 第一个链表头
 * @param h2 第二个链表头
 * @return
 */
template <typename T>
auto equal_list(ListNodeTemp<T>*&& h1, ListNodeTemp<T>*&& h2) -> bool {
  while (h1 && h2) {
    if (h1->val != h2->val) {
      return false;
    }
    h1 = h1->next;
    h2 = h2->next;
  }
  if (h1 || h2) {
    return false;
  }
  return true;
}

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    auto begin_node = new ListNode(-1, head);  // 该组的前一个。
    auto dummy = begin_node;                   // 虚拟头节点
    bool end = false;
    while (!end) {
      auto curr = begin_node;
      for (int i = 1; i <= k; ++i) {
        curr = curr->next;
        if (!curr) {
          end = true;
          break;
        }
      }
      if (end) {
        continue;
      }
      auto next_group = curr->next;
      const auto end_of_group = curr;
      curr = begin_node->next;
      const auto new_end = curr;
      while (curr != end_of_group) {
        auto tmp = curr->next;
        curr->next = end_of_group->next;
        end_of_group->next = curr;
        curr = tmp;
      }
      new_end->next = next_group;
      begin_node->next = end_of_group;
      begin_node = new_end;
    }
    auto ans = dummy->next;
    delete dummy;
    return ans;
  }
};

TEST(test25, SAMPLE1) {
  Solution sol;
  auto l = new List(std::vector{1, 2, 3, 4, 5});
  auto ans = new List(std::vector{2, 1, 4, 3, 5});
  int k = 2;

  EXPECT_EQ(equal_list(sol.reverseKGroup(l->get_head(), k), ans->get_head()),
            true);
}

TEST(test25, SAMPLE2) {
  Solution sol;
  auto l = new List(std::vector{1, 2, 3, 4, 5});
  auto ans = new List(std::vector{3, 2, 1, 4, 5});
  int k = 3;

  EXPECT_EQ(equal_list(sol.reverseKGroup(l->get_head(), k), ans->get_head()),
            true);
}