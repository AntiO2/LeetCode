/**
 * @author Anti
 * @date 2023/11/8
 * @see https://leetcode.cn/problems/find-median-from-data-stream
 */

#include <queue>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {};  // fill in it
class MedianFinder {
 private:
  std::priority_queue<int, std::vector<int>, std::less<int>> min_heap;
  // 小于等于中位数的heap，大根堆
  std::priority_queue<int, std::vector<int>, std::greater<int>>
      max_heap;  // 小根堆,大于中位数的部分
  std::unique_ptr<double> mid{nullptr};

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (mid == nullptr) {
      mid = std::make_unique<double>(num);
      min_heap.emplace(num);
      return;
    }
    if (min_heap.size() == max_heap.size()) {
      if (num <= max_heap.top()) {
        min_heap.emplace(num);
      } else {
        min_heap.emplace(max_heap.top());
        max_heap.pop();
        max_heap.emplace(num);
      }
      *mid = min_heap.top();
    } else {
      if (min_heap.size() > max_heap.size()) {
        if (min_heap.top() <= num) {
          max_heap.emplace(num);
        } else {
          max_heap.emplace(min_heap.top());
          min_heap.pop();
          min_heap.emplace(num);
        }
      } else {
        if (max_heap.top() >= num) {
          min_heap.emplace(num);
        } else {
          min_heap.emplace(max_heap.top());
          max_heap.pop();
          max_heap.emplace(num);
        }
      }
      *mid = ((double)min_heap.top() + max_heap.top()) / 2;
    }
  }

  double findMedian() { return *mid; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
TEST(test295, SAMPLE1) {
  Solution sol;
}

TEST(test295, SAMPLE2) {
  Solution sol;
}