/**
 * @author Anti
 * @date 2023-12-02
 * @see https://leetcode.cn/problems/print-in-order
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <future>
class Foo {
 private:
  std::promise<void> p1,p2;
 public:
  Foo() {

  }

  void first(std::function<void()> printFirst) {

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    p1.set_value();
  }

  void second(std::function<void()> printSecond) {
    p1.get_future().wait();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    p2.set_value();
  }

  void third(std::function<void()> printThird) {
    p2.get_future().wait();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
}; // print-in-order
