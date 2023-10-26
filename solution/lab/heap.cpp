//
// Created by Anti on 2023/10/26.
//
#include <queue>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Heap {};

TEST(test_heap, SAMPLE1) {
  std::priority_queue<int> pq;
  pq.push(1);
  pq.pop();
}

TEST(test_heap, SAMPLE2) {}