/**
 * @author Anti
 * @date 2023-11-28
 * @see https://leetcode.cn/problems/design-front-middle-back-queue
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <deque>
class FrontMiddleBackQueue {
 private:
  std::deque<int> first_half_, last_half_;
 public:
  FrontMiddleBackQueue() {

  }

  void pushFront(int val) {
    first_half_.push_front(val);
    if(first_half_.size()>last_half_.size()+1  ) {
      last_half_.push_front(first_half_.back());
      first_half_.pop_back();
    }
  }

  void pushMiddle(int val) {
    if(first_half_.size() > last_half_.size()) {
      last_half_.push_front(first_half_.back());
      first_half_.pop_back();
      first_half_.push_back(val);
    } else {
      first_half_.push_back(val);
    }
  }

  void pushBack(int val) {
    last_half_.push_back(val);
    if(last_half_.size() > first_half_.size()) {
      first_half_.push_back(last_half_.front());
      last_half_.pop_front();
    }
  }

  int popFront() {
    if(first_half_.empty()) {
      return -1;
    }
    auto tmp = first_half_.front();
    first_half_.pop_front();
    if(first_half_.size()  < last_half_.size()) {
      first_half_.push_back(last_half_.front());
      last_half_.pop_front();
    }
    return tmp;
  }

  int popMiddle() {
    if(first_half_.empty()) {
      return -1;
    }
    auto tmp = first_half_.back();
    first_half_.pop_back();
    if(first_half_.size()  < last_half_.size()) {
      first_half_.push_back(last_half_.front());
      last_half_.pop_front();
    }
    return tmp;
  }

  int popBack() {
    if(last_half_.empty()) {
      if(first_half_.empty()) {
        return -1;
      }
      auto tmp = first_half_.back();
      first_half_.pop_back();
      return tmp;
    }
    auto tmp = last_half_.back();
    last_half_.pop_back();
    if(first_half_.size()  > last_half_.size() + 1) {
      last_half_.push_front(first_half_.back());
      first_half_.pop_back();
    }
    return tmp;
  }
}; // design-front-middle-back-queue

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

TEST(test1670, SAMPLE1) {
    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushFront(2);
    q.pushFront(3);
    q.pushFront(4);
    EXPECT_EQ(q.popBack(),1);
    EXPECT_EQ(q.popBack(),2);
    EXPECT_EQ(q.popBack(),3);
    EXPECT_EQ(q.popBack(),4);
}

TEST(test1670, SAMPLE2) {
}