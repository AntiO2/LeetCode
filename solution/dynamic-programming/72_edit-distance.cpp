/**
 * @author Anti
 * @date 2023/11/9
 * @see https://leetcode.cn/problems/edit-distance
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int minDistance(std::string word1, std::string word2) {
    int n = word1.length();
    int m = word2.length();

    // 有一个字符串为空串
    if (n * m == 0)
      return n + m;

    std::vector<std::vector<int>> D(n + 1, std::vector<int>(m + 1));

    // 边界状态初始化
    for (int i = 0; i < n + 1; i++) {
      // 第二个字符串从无到转移到i，需要插入i次。
      D[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
      D[0][j] = j;
    }

    // 计算所有 DP 值
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        int left = D[i - 1][j] + 1;  // 从i-1插入一个
        int down = D[i][j - 1] + 1;  // 从第二个字符串插入一个，形成匹配
        int left_down = D[i - 1][j - 1];
        if (word1[i - 1] != word2[j - 1])
          left_down += 1;
        D[i][j] = std::min(left, std::min(down, left_down));
      }
    }
    return D[n][m];
  }
};

TEST(test72, SAMPLE1) {
  Solution sol;
}

TEST(test72, SAMPLE2) {
  Solution sol;
}