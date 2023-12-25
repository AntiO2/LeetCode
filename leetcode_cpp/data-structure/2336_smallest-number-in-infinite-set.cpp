/**
 * @author Anti
 * @date 2023-11-29
 * @see https://leetcode.cn/problems/smallest-number-in-infinite-set
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class SmallestInfiniteSet {
 private:
  int threshold_ = 1; // 下一个弹出的数子
  std::set<int> available_;
 public:
  SmallestInfiniteSet() {

  }

  int popSmallest() {
    if(available_.empty()) {
      return threshold_++;
    }
    auto tmp = *available_.begin();
    available_.erase(tmp);
    return tmp;
  }

  void addBack(int num) {
    if(num < threshold_) {
      available_.emplace(num);
    }
    return ;
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */  // smallest-number-in-infinite-set

TEST(test2336, SAMPLE1) {
  Solution sol;
}

TEST(test2336, SAMPLE2) {
  Solution sol;
}