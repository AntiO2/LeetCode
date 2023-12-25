/**
 * @author Anti
 * @date 2023/10/23
 * @see https://leetcode.cn/problems/search-a-2d-matrix-ii
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 private:
  /**
   *
   * @param matrix
   * @param target
   * @param x1 第一维下限
   * @param y1 第二维下限
   * @param x2 第一维上限
   * @param y2 第二维上限
   * @return
   */
  bool search_sub_matrix(const std::vector<std::vector<int>>& matrix,
                         int target, int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) {
      return false;
    }
    // LOG_INFO("%s", fmt::format("Search {} {} {} {}", x1, y1, x2,
    // y2).c_str());
    auto c = matrix[x1][y2];
    if (c == target) {
      return true;
    }
    if (c > target) {
      return search_sub_matrix(matrix, target, x1, y1, x2, y2 - 1);
    }
    // c < target
    return search_sub_matrix(matrix, target, x1 + 1, y1, x2, y2);
  }

 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    return search_sub_matrix(matrix, target, 0, 0, matrix.size() - 1,
                             matrix.at(0).size() - 1);
  }
};

TEST(test240, SAMPLE1) {
  Solution sol;
  std::vector<std::vector<int>> m{{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
  EXPECT_EQ(sol.searchMatrix(m, 5), true);
}

TEST(test240, SAMPLE2) {
  Solution sol;
  std::vector<std::vector<int>> m{{1, 3, 5}};
  EXPECT_EQ(sol.searchMatrix(m, 1), true);
}

TEST(test240, SAMPLE3) {
  Solution sol;
  std::vector<std::vector<int>> m{{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
  EXPECT_EQ(sol.searchMatrix(m, 20), false);
}
TEST(test240, SAMPLE4) {
  Solution sol;
  std::vector<std::vector<int>> m{{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20},
                                  {21, 22, 23, 24, 25}};
  EXPECT_EQ(sol.searchMatrix(m, 5), true);
}