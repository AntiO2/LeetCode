//
// Created by Anti on 2024-01-25.
//
#include "logger.h"
class Datum {
 public:
  int a;
  explicit Datum(int a) : a(a) {}
  Datum() {}
  Datum& operator=(Datum&&d) {
    this->a = d.a;
    d.a = -1;
    return *this;
  }
  Datum& operator=(Datum&d) {
    this->a = d.a;
    d.a = -1;
    return *this;
  }
};
class A {
 private:
  Datum d_;
 public:
  A(int a): d_(a){};
  A(A&a): d_(a.d_.a){};
  A(A&&a) {
    d_=std::move(a.d_);
  }

  A operator=(A& a) {
    a.d_=a.d_;
  }
  A operator=(A&&a) {
    a.d_ = std::move(a.d_);
  }
  int get_val() {
    return d_.a;
  }
};

int main() {
  A a(1);
  A b(a);
  A c(std::move(a));
  LOG_INFO("%d %d %d",a.get_val(), b.get_val(), c.get_val());
}