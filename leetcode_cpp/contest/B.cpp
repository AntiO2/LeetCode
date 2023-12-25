/**
 * @author Anti
 * @date 2023-12-03
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  int minimumAddedCoins(std::vector<int>& coins, int target) {
    std::sort(coins.begin(), coins.end());
    long long max = 0;
    int ans = 0;
    auto iter = coins.begin();
    for(long long i = 0; i <= target;i++) {
      while(iter!=coins.end()&&*iter<=i) {
        max+=*iter;
        ++iter;
      }
      if(max<i) {

        max+=i;
        ans++;
       // LOG_INFO("Add %d Max: %d",i,max);
      }
    }
    return ans;
  }
};

TEST(C374_2,A) {
  Solution s;
  std::vector coins{1,4,10};
  int  target = 19;
  EXPECT_EQ(s.minimumAddedCoins(coins,target),2);
}

TEST(C374_2,B) {
  Solution s;
  std::vector coins{15,1,12};
  int  target = 43;
  EXPECT_EQ(s.minimumAddedCoins(coins,target),4);
}
