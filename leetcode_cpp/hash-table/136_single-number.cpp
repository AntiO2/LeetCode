//
// Created by Anti on 2023/10/14.
//
#include <unordered_set>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    // std::unordered_set<int> book;
    // for (auto &num: nums) {
    //     auto iter = book.find(num);
    //     if (iter == book.end()) {
    //         book.emplace(num);
    //     } else {
    //         book.erase(iter);
    //     }
    // }
    // return *book.begin();
    int ans = 0;
    std::for_each(nums.begin(), nums.end(), [&ans](int a) { ans ^= a; });
    return ans;
  }
};

TEST(test136, SAMPLE1) {
  Solution s;
  std::vector nums{2, 2, 1};
  int ans = 1;
  EXPECT_EQ(s.singleNumber(nums), ans);
  // LOG_INFO("SAMPLE1 PASS");
}

TEST(test136, SAMPLE2) {
  Solution s;
  std::vector nums{4, 1, 2, 1, 2};
  int ans = 4;
  EXPECT_EQ(s.singleNumber(nums), ans);
  // LOG_INFO("SAMPLE2 PASS");
}

TEST(test136, SAMPLE3) {
  Solution s;
  std::vector nums{1};
  int ans = 1;
  EXPECT_EQ(s.singleNumber(nums), ans);
  // LOG_INFO("SAMPLE2 PASS");
}