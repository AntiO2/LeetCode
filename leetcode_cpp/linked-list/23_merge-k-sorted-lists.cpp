// Copyright (c) 2023. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam
// lacinia accumsan. Etiam sed turpis ac ipsum condimentum fringilla. Maecenas
// magna. Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque
// sagittis ligula eget metus. Vestibulum commodo. Ut rhoncus gravida arcu.

/**
 * @author Anti
 * @date 2023/10/27
 * @see https://leetcode.cn/problems/merge-k-sorted-lists
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
#include <queue>
class Solution {
 private:
  struct cmp {
    bool operator()(ListNode* n1, ListNode* n2) { return n1->val > n2->val; }
  };

 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::vector<ListNode*> heads;
    for (auto list : lists) {
      if (list) {
        heads.push_back(list);
      }
    }
    std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> pq(
        heads.begin(), heads.end());
    auto dummy = new ListNode(0);
    auto curr = dummy;
    while (!pq.empty()) {
      auto top = pq.top();
      pq.pop();
      curr->next = top;
      curr = top;
      if (top->next) {
        pq.emplace(top->next);
      }
    }
    return dummy->next;
  }
};

TEST(test23, SAMPLE1) {
  Solution sol;
  std::vector<std::vector<int>> numss{std::vector<int>{1, 4, 5},
                                      std::vector<int>{1, 3, 4},
                                      std::vector<int>{2, 6}};
  std::vector ans{1, 1, 2, 3, 4, 4, 5, 6};
  std::vector<ListNode*> list_heads;
  for (auto& nums : numss) {
    auto l = new List(nums);
    list_heads.push_back(l->get_head());
  }
  EXPECT_EQ((equal_list(sol.mergeKLists(list_heads), List(ans).get_head())),
            true);
}

TEST(test23, SAMPLE2) {
  Solution sol;
}