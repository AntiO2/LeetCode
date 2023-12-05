//
// Created by Anti on 2023-12-05.
//

#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H
#include <vector>
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
#endif  // LEETCODE_LIST_H
