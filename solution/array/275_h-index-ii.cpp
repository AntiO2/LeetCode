/**
 * @author Anti
 * @date 2023/10/30
 * @see https://leetcode.cn/problems/h-index-ii
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int hIndex(std::vector<int>& citations) {
    auto n = int(citations.size());
    auto lower = 0;
    auto upper = n;  // 假设一共有n篇论文，都被引用n次，是最好情况。
    auto ans = 0;
    while (lower <= upper) {
      auto mid =
          (lower + upper) /
          2;  // mid是否成立呢？如果h指数大于等于mid，那么至少有mid篇论文的引用次数大于mid。也就是说，倒数第mid篇的引用次数大于等于mid,答案肯定是大于mid的。
      if (mid == 0) {
        lower = mid + 1;
        continue;
      }
      if (citations[n - mid] >= mid) {
        ans = mid;
        lower = mid + 1;
      } else {
        upper = mid - 1;
      }
    }
    return ans;
  }
};

TEST(test275, SAMPLE1) {
  Solution sol;
  std::vector c{0, 1, 3, 5, 6};
  int ans = 3;
  EXPECT_EQ(sol.hIndex(c), ans);
}

TEST(test275, SAMPLE2) {
  Solution sol;
  std::vector c{1, 2, 100};
  int ans = 2;
  EXPECT_EQ(sol.hIndex(c), ans);
}

TEST(test275, SAMPLE3) {
  Solution sol;
  std::vector c{0};
  int ans = 0;
  EXPECT_EQ(sol.hIndex(c), ans);
}
TEST(test275, SAMPLE4) {
  Solution sol;
  std::vector c{1};
  int ans = 1;
  EXPECT_EQ(sol.hIndex(c), ans);
}