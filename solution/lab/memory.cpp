/**
 * @author Anti
 * @date 2023-12-19
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Data {
 public:
  int a;
  int b;
  explicit Data()=default;
};

TEST(DATA,DATA1) {
  /**
   * 在windows环境下，栈地址比堆地址低。
   * 在Linux环境下，堆位于低地址。
   */
  auto heap = new Data;
  LOG_INFO("%p",&(heap->a));
  LOG_INFO("%p",&(heap->b));
  delete heap;
  Data d{};
  LOG_INFO("%p",&(d.a));
  LOG_INFO("%p",&(d.b));
}