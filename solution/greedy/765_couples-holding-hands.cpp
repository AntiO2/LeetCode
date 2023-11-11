/**
 * @author Anti
 * @date 2023/11/11
 * @see https://leetcode.cn/problems/couples-holding-hands
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  int getf(std::vector<int>& f, int x) {
    if (f[x] == x) {
      return x;
    }
    return f[x] = getf(f, f[x]);
  }
  void add(std::vector<int>& f, int x, int y) {
    auto fx = getf(f, x);
    auto fy = getf(f, y);
    if (fx < fy) {
      f[fy] = fx;
    } else {
      f[fx] = fy;
    }
  }

 public:
  int minSwapsCouples(std::vector<int>& row) {
    int n = row.size();
    int couple = n / 2;
    std::vector f(couple, 0);
    for (int i = 0; i < couple; i++) {
      f[i] = i;
    }
    for (int i = 0; i < n; i += 2) {
      add(f, row[i] / 2, row[i + 1] / 2);
    }
    std::unordered_map<int, int> m;
    for (int i = 0; i < couple; i++) {
      m[getf(f, i)]++;  // 该对情侣所在联通分量的大小。
    }
    int ans = 0;
    for (auto& [i, num] : m) {
      ans += (num - 1);
    }
    return ans;
  }
};  // couples-holding-hands

TEST(test765, SAMPLE1) {
  Solution sol;
}

TEST(test765, SAMPLE2) {
  Solution sol;
}