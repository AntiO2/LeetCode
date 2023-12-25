/**
 * @author Anti
 * @date 2023/11/16
 * @brief rbt
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  std::set<int> set_;

 public:
  void init() {
    for (int i = 0; i < 10; i++) {
      set_.insert(i);
    }
  }
};  // rbt

TEST(testrbt, SAMPLE1) {
  Solution sol;
  sol.init();
}

TEST(rbt, SAMPLE2) {
  const int&& a = 1;
  LOG_INFO("%p", &a);
}