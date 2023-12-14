/**
 * @author Anti
 * @date 2023-12-14
 * @see https://www.luogu.com.cn/problem/P3378
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <vector>
#include <functional>
#include <iostream>
template<class T>
class Heap {

  std::vector<T> v_;
  std::function<bool(T,T)> cmp;
  inline auto get_parent(int x)-> int{
    if(x==0) {
      throw std::runtime_error("Try Get Parent of Index 0");
    }
    return (x-1)/2;
  }
  inline auto get_left_child(int x)-> int {
    return x<<1|1;
  }
  inline auto get_right_child(int x) -> int {
    return (x<<1)+2;
  }
  void push_heap() {
    int hole_index = v_.size() - 1;
    auto hole_value = std::move(v_.back());
    while(hole_index > 0) {
      auto parent = get_parent(hole_index);
      if(cmp(v_[parent], hole_value)) {
        v_[hole_index] = std::move(v_[parent]);
        hole_index = parent;
      } else {
        break ;
      }
    }
    v_[hole_index] = std::move(hole_value);
  }
  void adjust_heap(T && value) {
    auto hole_value = std::move(value);
    auto hole_index = 0;
    auto r_child = get_right_child(hole_index);
    auto l = v_.size();
    while(r_child < l) {
      auto l_child = get_left_child(hole_index);
      if(cmp(v_[l_child], v_[r_child])) {
        std::swap(l_child, r_child);
      }
      if(cmp(hole_value,v_[l_child])) {
        v_[hole_index] = std::move(v_[l_child]);
        hole_index = l_child;
        r_child = get_right_child(hole_index);
      } else {
        break ;
      }
    }
    auto l_child = get_left_child(hole_index);
    if(l_child < l&&cmp(hole_value,v_[l_child])) {
      v_[hole_index] = std::move(v_[l_child]);
      hole_index = l_child;
    }
    v_[hole_index] = std::move(hole_value);
  }
 public:
  Heap() = default;
  Heap(  std::function<bool(T,T)> c): cmp(c){};
  void add(T t) {
    v_.emplace_back(std::move(t));
    push_heap();
  }
  T get() {
    if(v_.empty()) {
      throw std::runtime_error("Heap is empty");
    }
    return v_.at(0);
  }
  void pop() {
    v_[0] = std::move(v_.back());
    v_.pop_back();
    adjust_heap(std::move(v_[0]));
  }
};

class Wrapper {
 private:
  std::function<bool(int,int)> cmp = [](const int x,const int y) {
    return x > y;
  };
  Heap<int> h_{cmp};
 public:
  void process() {
    int t;
    std::cin>>t;
    while(t--) {
      int op;
      std::cin>>op;
      switch (op) {
        case 1: {
          int value;
          std::cin>>value;
          h_.add(std::move(value));
          break ;
        }
        case 2: {
          std::cout<<h_.get()<<std::endl;
          break ;
        }
        case 3: {
          h_.pop();
          break ;
        }
        default:
          throw std::runtime_error("Error Op");
      }
    }
  }
  void add(int x) {
    h_.add(x);
  }
  void pop() {
    h_.pop();
  }
  auto get()->int {
    h_.get();
  }
};

int main() {
  Wrapper w;
  w.process();
}
TEST(H,h1) {
  Wrapper w;
  w.add(1);
  w.add(2);
  w.add(3);
  EXPECT_EQ(w.get(),1);
  w.pop();
  EXPECT_EQ(w.get(),2);
}
TEST(H,T2) {
  Wrapper w;
  w.add(5384);
  EXPECT_EQ(w.get(),5384);
  w.pop();
  w.add(4337);
  w.add(291);
  w.pop();
  w.add(3776);
  EXPECT_EQ(w.get(),3776);
}
TEST(H,T3) {
  Wrapper w;
  w.add(9336);
  w.add(9645);
  w.add(5524);
  w.add(1760);
  w.pop();
  w.add(7777);
 EXPECT_EQ(w.get(),5524);
}