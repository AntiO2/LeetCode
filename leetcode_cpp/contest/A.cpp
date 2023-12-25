/**
 * @author Anti
 * @date 2023-12-03
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 public:
  std::vector<int> findPeaks(std::vector<int>& mountain) {
        std::vector<int> ans;
        auto n = mountain.size();
        auto prev = mountain.at(0);
        for(int i = 1; i < n-1;i++) {
          if(mountain[i]>mountain[i-1]&&mountain[i]>mountain[i+1]) {
            ans.emplace_back(i);
          }
        }
        return ans;
  }
};