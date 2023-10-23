/**
 * @author Anti
 * @date 2023/10/23
 * @see https://leetcode.cn/problems/number-of-senior-citizens
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  int countSeniors(std::vector<std::string>& details) {
    int ans = 0;
    for (auto& s : details) {
      //      if ((s[11] - '0') * 10 + s[12] - '0' > 60) {
      if (s[11] * 10 + s[12] > 588) {
        ++ans;
      }
    }
    return ans;
  }
};

TEST(test2768, SAMPLE1) {
  Solution sol;
  std::vector<std::string> d{"7868190130M7522", "5303914400F9211",
                             "9273338290F4010"};
  EXPECT_EQ(sol.countSeniors(d), 2);
}

TEST(test2768, SAMPLE2) {
  Solution sol;
  LOG_INFO("%d", 60 + '0' * 11);
}