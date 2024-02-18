/**
 * @author Anti
 * @date 2024-02-06
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

TEST(CONST,T1) {
  const int a = 1;
  int const b = 1;
  const int* p = &a;
  int c = 1, d= 1;
  p = &b;
  // *p = 1;
  int* const p2 = &c;
  // p2 = & d;
  int const * p3 = &c;
  p3 = &d;
  // *p3 = 2;
  // p2 = &a;
  static const int cs = 1;
}

class A {
 private:
  int val_;
  int* pa;
  static  int sv_;
 public:
  A() {
    pa = new int(1);
  }
  void fun1() {
    val_ = 1;
  }
  void const_fun() const {
    // val_ = 1;
    sv_ = 1;
    *pa = 2;
  }

};

class Obj {
 private:
  static int val_;
  mutable int a;
 public:
  void fun() const {
    Obj::val_ = 1;
    a = 1;
  }
};
TEST(CONST,CLASS) {
  const A a{};
  // a.fun1();
  a.const_fun();
}

void func(const int& a) {

}
TEST(CONST,FUNC) {
  int a = 1;
  func(a);
}