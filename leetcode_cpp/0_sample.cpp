/**
 * @author Anti
 * @date 2023/9/1
 * @see https://leetcode.cn/problems/sample
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {

 public:
  void test() { LOG_INFO("TEST SOL"); }
};  // fill in it

TEST(test0, SAMPLE1) {
  Solution sol;
}

TEST(test0, SAMPLE2) {
  Solution sol;
}

TEST(test0, DISABLED_ASAN_TEST) {
  // 栈内存越界
  int array[3]{0, 1, 2};
  LOG_INFO("%d", array[3]);
  // 堆内存越界
  auto stack_array = new int[3];
  LOG_INFO("%d", stack_array[3]);

  auto memory_leak = new int[3];  // 内存泄露
  // delete[] memory_leak;
  auto s = new Solution();
  delete s;
  s->test();  // use after free;
}
