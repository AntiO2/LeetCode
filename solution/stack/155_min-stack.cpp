/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/min-stack
 */

#include <stack>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class MinStack {
 private:
  std::stack<long long> s_;
  long long min_;

 public:
  MinStack() : s_(), min_(0) {}

  void push(int val) {
    if (s_.empty()) {
      min_ = val;
    }
    s_.push(val - min_);
    if (val < min_) {
      min_ = val;
    }
  }

  void pop() {
    auto val = s_.top();
    s_.pop();
    if (val < 0) {
      // 说明最小值应该变大。
      min_ = min_ - val;
    }
  }

  int top() {
    if (s_.top() < 0) {
      return min_;
    }
    return min_ + s_.top();
  }

  int getMin() { return min_; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class Solution {};  // fill in it

TEST(test155, SAMPLE1) {
  Solution sol;
}

TEST(test155, SAMPLE2) {
  Solution sol;
}