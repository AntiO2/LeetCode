/**
 * @author Anti
 * @date 2023-11-26
 * @see https://leetcode.cn/problems/a
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  bool areSimilar(std::vector<std::vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat.at(0).size();
        for(int i = 0; i<n;i++) {
          bool flag = (i+1)%2;
          for(int j = 0; j < m; j++) {
            //std::cout<<i<<" "<<j<<" "<<(j+k)%m<<" "<< (j+m-k)%m<<std::endl;
            if(flag&&mat[i][j]!=mat[i][(j+k)%m]) {
              return false;
            }
            if(!flag&&mat[i][j]!=mat[i][(j+m-k%m)%m]) {
              return false;
            }
          }
        }
        return true;
  }
};  // a

TEST(test2946, SAMPLE1) {
  Solution sol;
}

TEST(test2946, SAMPLE2) {
  Solution sol;
}