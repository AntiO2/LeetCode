//
// Created by Anti on 2023/9/22.
//

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int distMoney(int money, int children) {
    money -= children;  // 先每人分一个糖果
    if (money < 0) {
      return -1;
    }
    auto ans = std::min(money / 7, children);
    auto rest = money - ans * 7;  // 有ans人分配到8个糖果后，剩余的糖果数量
    if (ans == children) {
      if (rest) {
        return children - 1;
      } else {
        return children;
      }
    }
    if (ans == children - 1 && rest == 3) {
      // 必须有一个人分配到3个糖果
      return ans - 1;
    }
    return ans;
  }
};

TEST(test2591, SAMPLE1) {
  Solution s;
  int money = 20, children = 3;
  EXPECT_EQ(s.distMoney(money, children), 1);
}

TEST(test2591, SAMPLE2) {
  Solution s;
  int money = 16, children = 2;
  EXPECT_EQ(s.distMoney(money, children), 2);
}
TEST(test2591, SAMPLE3) {
  Solution s;
  int money = 13, children = 3;
  EXPECT_EQ(s.distMoney(money, children), 1);
}

TEST(test2591, SAMPLE4) {
  Solution s;
  int money = 17, children = 2;
  EXPECT_EQ(s.distMoney(money, children), 1);
}