/**
 * @author Anti
 * @date 2023/10/31
 * @see https://leetcode.cn/problems/course-schedule
 */

#include <list>
#include <queue>
#include <unordered_set>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
//
class Solution {
 public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> inDegree(numCourses, 0);            // 入度
    std::vector<std::list<int>> nextCourse(numCourses);  // 存储边。
    std::queue<int> zero_node;
    for (auto& edge : prerequisites) {
      ++inDegree[edge.at(1)];
      nextCourse[edge.at(0)].emplace_back(edge.at(1));
    }
    int cnt = 0;
    for (int i = 0; i < numCourses; ++i) {
      if (inDegree[i] == 0) {
        ++cnt;
        zero_node.emplace(i);
      }
    }
    while (!zero_node.empty()) {
      auto i = zero_node.front();
      zero_node.pop();
      for (auto& next : nextCourse[i]) {
        if (--inDegree[next] == 0) {
          ++cnt;
          zero_node.emplace(next);
        }
      }
    }
    return cnt == numCourses;
  }
};

TEST(test207, SAMPLE1) {
  Solution sol;
  int n = 2;
  std::vector<std::vector<int>> pre{std::vector{1, 0}};
  EXPECT_EQ(sol.canFinish(n, pre), true);
}

TEST(test207, SAMPLE2) {
  Solution sol;
  int n = 2;
  std::vector<std::vector<int>> pre{std::vector{1, 0}, std::vector{0, 1}};
  EXPECT_EQ(sol.canFinish(n, pre), false);
}