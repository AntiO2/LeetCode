/**
 * @author Anti
 * @date 2023-12-27
 * @see https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <queue>
class Solution {
 private:
  auto calculate_score(const std::vector<int>& record) -> int {
    auto n = record.size();
    std::queue<int> q;
    int score = 0;
    for(int i = 0; i < n;i++) {
        if(!q.empty()&&i - q.front() > 2) {
          q.pop();
        }
        score += (record[i] + (q.empty()?0:record[i])) ;
        if(record[i]==10) {
          q.emplace(i);
        }
    }
    return score;
  }
 public:
  int isWinner(std::vector<int>& player1, std::vector<int>& player2) {
    auto s1 = calculate_score(player1), s2 = calculate_score(player2);
    if(s1==s2) {
      return 0;
    }
    if(s1 > s2) {
      return 1;
    }
    return 2;
  }
};  // determine-the-winner-of-a-bowling-game

TEST(test2660, SAMPLE1) {
  Solution sol;
  std::vector p1{5,6,1,10};
  std::vector p2{5,1,10,5};

  EXPECT_EQ(sol.isWinner(p1,p2),2);
}

TEST(test2660, SAMPLE2) {
  Solution sol;
}