/**
 * @author Anti
 * @date 2023/9/1
 * @see https://leetcode.cn/problems/sample
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class A {
 public:
  virtual void m1() { LOG_INFO("A"); }
  virtual ~A() { LOG_INFO("Delete A"); }
};

class B : public A {
 public:
  void m1() override { LOG_INFO("B"); }
  ~B() override { LOG_INFO("Delete B"); }
};

TEST(TEST_POLY, VIRTUAL_FUNC) {
  B b;
  A* ap = &b;
  ap->m1();
  B* bp = &b;
  bp->m1();
}

TEST(TEST_POLY, DESTORY) {
  A* ap = new B();
  delete ap;
  LOG_INFO("---");
  B* bp = new B();
  delete bp;
}

class C {
 public:
  template <typename T>
  // virtual void func(){};
  void func(){};
};
TEST(TEST_POLY, VIRTUAL) {
  C c;
  c.func<int>();
  c.func<long>();
}

class Empty {};
template <class E>
class Empty2 {
 public:
  E e;
};
class Empty4 : Empty {
  virtual void func(){};
};
class Empty5 : Empty {
  void func(){};
};
TEST(TEST_EMPTY, SAMPLE) {
  Empty e1;
  LOG_INFO("%zu", sizeof(e1));
  Empty2<Empty> e2{};
  LOG_INFO("%zu", sizeof(e2));
  Empty2<int> e3{};
  LOG_INFO("%zu", sizeof(e3));
  Empty4 e4;
  LOG_INFO("%zu", sizeof(e4));
  Empty5 e5;
  LOG_INFO("%zu", sizeof(e5));
}
Empty e1;
Empty e2;
TEST(TEST_EMPTY, SAMPLE2) {
  LOG_INFO("%p", &e1);
  LOG_INFO("%p", &e2);
}