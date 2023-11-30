/**
 * @author Anti
 * @date 2023-11-30
 * @see https://leetcode.cn/problems/determine-if-two-strings-are-close
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  bool closeStrings(std::string word1, std::string word2) {
    auto l = word1.size();
    if(l!=word2.size()) {
      return false;
    }
    int cnt1[26]{0},cnt2[26]{0};
    for(int i = 0 ; i<l;i++) {
        ++cnt1[word1[i]-'a'];
        ++cnt2[word2[i]-'a'];
    }
    std::unordered_map<int,int> num_cnt;
    for(int i = 0; i < 26;i++) {
      if((cnt1[i]&&!cnt2[i])||(!cnt1[i]&&cnt2[i])) {
        return false;
      }
      num_cnt[cnt1[i]]++;
      num_cnt[cnt2[i]]--;
    }
    return std::all_of(num_cnt.begin(), num_cnt.end(),[](auto &cnt) {
      return cnt.second==0;
    });
  }
};  // determine-if-two-strings-are-close

TEST(test1657, SAMPLE1) {
  Solution sol;
  EXPECT_EQ(sol.closeStrings("abbccc","caabbb"), true);
}

TEST(test1657, SAMPLE2) {
  Solution sol;
  EXPECT_EQ(sol.closeStrings("abbzccca","abbzccca"), true);
}