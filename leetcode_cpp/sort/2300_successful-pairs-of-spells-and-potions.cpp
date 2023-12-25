/**
 * @author Anti
 * @date 2023/11/10
 * @see https://leetcode.cn/problems/successful-pairs-of-spells-and-potions
 */

#include <numeric>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  std::vector<int> successfulPairs(std::vector<int>& spells,
                                   std::vector<int>& potions,
                                   long long success) {
    auto n = spells.size();
    auto m = potions.size();
    std::vector<int> s_i(n);
    std::iota(s_i.begin(), s_i.end(), 0);  // spells的下标
    std::sort(s_i.begin(), s_i.end(), [&spells](auto& i1, auto& i2) {
      return spells[i1] < spells[i2];
    });
    std::sort(potions.begin(), potions.end());
    auto find_end = potions.end();
    std::vector ans(n, 0);
    // 从小到大的spell，可以选择的最小值是递减的。
    for (auto spell_i : s_i) {
      auto target =
          success / spells[spell_i] + ((success % spells[spell_i] > 0) ? 1 : 0);
      auto iter = std::lower_bound(potions.begin(), find_end, target);
      ans[spell_i] = std::distance(iter, potions.end());
      if (find_end != potions.end()) {
        find_end = std::next(iter);
      }
    }
    return ans;
  }
};  // successful-pairs-of-spells-and-potions

TEST(test2300, SAMPLE1) {
  Solution sol;
  std::vector spells{5, 1, 3};
  std::vector potions{1, 2, 3, 4, 5};
  int success = 7;
  std::vector ans{4, 0, 3};
  EXPECT_EQ(sol.successfulPairs(spells, potions, success), ans);
}

TEST(test2300, SAMPLE2) {
  Solution sol;
}