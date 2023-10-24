//
// Created by Anti on 2023/8/11.
//
#include <vector>
#include "fmt/core.h"
#include "gtest/gtest.h"

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    auto maintainer = 0;  // 从0-maintainer都是非0的数
    auto searcher = 0;    // searcher负责向右寻找
    auto len = nums.size();
    while (searcher < len) {
      if (nums.at(searcher) != 0) {
        std::swap(nums.at(maintainer), nums.at(searcher));
        maintainer++;
      }
      searcher++;
    }
  }
};

TEST(MOVE_ZERO, SAMPLE1) {
  std::vector<int> nums = {0, 1, 0, 3, 12};
  Solution s;
  s.moveZeroes(nums);
  std::for_each(nums.begin(), nums.end(),
                [](const int& num) { fmt::print("{} ", num); });
}