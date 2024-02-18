//
// Created by Anti on 2024-02-07.
//
#include "logger.h"
class A {
  private:
  int val_;
 public:
  A() {
    LOG_INFO("CONSTRUCT A");
  }
  A(const A&a):val_(a.val_) {
    LOG_INFO("COPY CONSTRUCT A");
  }
};

class B: public A {
 public:
  B(): b_(0) {};
  B(const B&b): A(b) {
    LOG_INFO("COPY CONSTRUCT B");
  }
  int b_;

  B& operator=(const B&rhs) {
    A::operator=(rhs);
  }
};

int main() {
  B b;
  b.b_ = 1;
  B b2(b);
  b2 = b;
}