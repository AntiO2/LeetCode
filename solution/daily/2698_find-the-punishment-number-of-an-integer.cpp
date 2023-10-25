/**
 * @author Anti
 * @date 2023/10/25
 * @see https://leetcode.cn/problems/find-the-punishment-number-of-an-integer
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  struct book_ {
    int data[1005]{};
    consteval book_() {
      int t = 0;
      for (int i = 1; i <= 1000; ++i) {
        int i2 = i * i;
        if (check(i2, i)) {
          t += i2;
        }
        data[i] = t;
      }
    }
    consteval bool check(int square, int n) {
      if (n == square) {
        return true;
      }
      int t = 10;
      while (t < square) {
        if (check(square / t, n - square % t)) {
          return true;
        }
        t *= 10;
      }
      return false;
    }
  };

 public:
  int punishmentNumber(int n) {
    constexpr book_ book;
    return book.data[n];
  }
};
TEST(test2698, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.punishmentNumber(10), 182);
}

TEST(test2698, SAMPLE2) {
  Solution sol;
}