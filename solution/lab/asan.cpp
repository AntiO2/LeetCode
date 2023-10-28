//
// Created by Anti on 2023/10/28.
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

struct A {
  int a_;
  A(int a) : a_(a){};
};
TEST(ASAN, USE_AFTER_FREE) {
  /**
   * 使用已释放内存（野指针）
   */
  auto a = new A(1);
  LOG_DEBUG("%d", a->a_);
  delete a;
  LOG_DEBUG("%d", a->a_);
}

TEST(ASAN, STACK_OVERFLOW) {
  // 栈内存越界
  int array[3]{0, 1, 2};
  LOG_INFO("%d", array[3]);
}

TEST(ASAN, HEAP_OVERFLOW) {
  // 堆内存越界
  auto array = new int[3];
  LOG_INFO("%d", array[3]);
}

TEST(ASAN, MEMORY_LEAK) {
  // 内存泄露
  auto array = new int[3];
}

TEST(ASAN, NO_MEMORY_LEAK) {
  // 内存没泄露
  auto array = new int[3];
  delete[] array;
}

int global_array[3];
TEST(ASAN, GLOBAL_BUFFER_OVERFLOW) {
  // 内存没泄露
  LOG_INFO("%d", global_array[3]);
}

int* getLocalArray() {
  int local_array[3] = {4, 5, 6};
  return local_array;
}

TEST(ASAN, GET_LOCAL_ARRAY) {
  // 内存没泄露
  auto local = getLocalArray();
  LOG_INFO("%d", local[0]);
}