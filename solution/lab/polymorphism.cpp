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