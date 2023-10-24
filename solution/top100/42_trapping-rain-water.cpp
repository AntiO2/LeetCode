//
// Created by Anti
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int trap(std::vector<int>& height) {
    if (height.size() <= 2) {
      return 0;
    }
    int left = 1,
        right = int(height.size()) - 2;  // 检测left或right位置能否接水
    auto left_board = height.front(), right_board = height.back();
    int ans = 0;
    while (left <= right) {
      if (left_board <= right_board) {
        // left列接的水不可能随着右侧边界移动增大
        if (left_board > height.at(left)) {
          ans += left_board - height.at(left);

        } else {
          left_board = height.at(left);
        }
        ++left;
      } else {
        if (right_board > height.at(right)) {
          ans += right_board - height.at(right);
        } else {
          right_board = height.at(right);
        }
        --right;
      }
    }
    return ans;
  }
};

class test42 : public testing::Test {
 public:
  Solution s;

 protected:
  void SetUp() override { Test::SetUp(); }

  void TearDown() override { Test::TearDown(); }
};

TEST_F(test42, SAMPLE1) {
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto ans = this->s.trap(height);
  LOG_DEBUG("ans is %d\n", ans);
  EXPECT_EQ(ans, 6);
}
TEST_F(test42, SAMPLE2) {
  std::vector<int> height = {4, 2, 0, 3, 2, 5};
  auto ans = this->s.trap(height);
  LOG_DEBUG("ans is %d\n", ans);
  EXPECT_EQ(ans, 9);
}
TEST_F(test42, SAMPLE3) {
  std::vector<int> height = {0};
  auto ans = this->s.trap(height);
  LOG_DEBUG("ans is %d\n", ans);
  EXPECT_EQ(ans, 0);
}

TEST(stest, SAMPLE2) {
  Solution s;
  std::vector<int> height = {4, 2, 0, 3, 2, 5};
  auto ans = s.trap(height);
  LOG_DEBUG("ans is %d\n", ans);
  EXPECT_EQ(ans, 9);
}