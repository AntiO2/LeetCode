/**
 * @author Anti
 * @date 2024-01-07
 * @see https://leetcode.cn/problems/ransom-note
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    int a[26]{};
    int b[26]{};
    for(auto c:ransomNote) {
      a[c-'a']++;
    }
    for(auto c:magazine) {
      b[c-'a']++;
    }
    for(int i = 0 ; i<26;i++) {
      if(a[i]>b[i]) {
        return false;
      }
    }
    return true;
  }
};  // ransom-note

TEST(test383, SAMPLE1) {
  Solution sol;
}

TEST(test383, SAMPLE2) {
  Solution sol;
}