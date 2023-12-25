// Copyright (c) 2023. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam
// lacinia accumsan. Etiam sed turpis ac ipsum condimentum fringilla. Maecenas
// magna. Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque
// sagittis ligula eget metus. Vestibulum commodo. Ut rhoncus gravida arcu.

/**
 * @author Anti
 * @date 2023/10/27
 * @see https://leetcode.cn/problems/sort-list
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
 private:
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

 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    int sublength = 1;
    auto curr = head;
    auto dummy = new ListNode(0, head);
    auto length = 0;
    while (curr) {
      ++length;
      curr = curr->next;
    }
    while (sublength < length) {
      // 根据进行分割
      auto prev = dummy;
      curr = dummy->next;

      while (curr) {
        auto head1 = curr;
        for (int i = 1; i < sublength && curr; i++) {
          curr = curr->next;
        }
        if (!curr) {
          prev->next = head1;
          break;
        }
        auto head2 = curr->next;
        curr->next = nullptr;
        curr = head2;
        for (int i = 1; i < sublength && curr; i++) {
          curr = curr->next;
        }
        ListNode* next = nullptr;
        if (curr) {
          next = curr->next;
          curr->next = nullptr;
        }
        prev->next = mergeTwoLists(head1, head2);
        while (prev->next) {
          prev = prev->next;  // 找到末尾
        }
        curr = next;
      }
      sublength <<= 1;
    }
    return dummy->next;
  }
};

TEST(test148, SAMPLE1) {
  Solution sol;
  auto l = List(std::vector{-1, 5, 3, 4, 0});
  auto ans = List(std::vector{-1, 0, 3, 4, 5});
  EXPECT_EQ(equal_list(sol.sortList(l.get_head()), ans.get_head()), true);
}

TEST(test148, SAMPLE2) {
  Solution sol;
}