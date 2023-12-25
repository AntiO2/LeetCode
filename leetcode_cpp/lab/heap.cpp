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
void move(std::vector<int>& v) {
  std::vector tmp{1, 2, 3};
  LOG_INFO("tmpP: %p", &tmp);
  LOG_INFO("vp:%p", &v);
  v = std::move(tmp);
  LOG_INFO("vp:%p", &v);
}
TEST(test_move, SAMPLE2) {
  std::vector<int> v{};
  LOG_INFO("vp:%p", &v);
  move(v);
  LOG_INFO("vp:%p", &v);
}