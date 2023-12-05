/**
 * @author Anti
 * @date 2023-12-03
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
class Solution {
 private:
  std::vector<std::vector<int>> cnt_;
  std::vector<std::vector<int>> pos[26];
  int handleSubstr(std::string &word,int begin,int end,int k) {
    if(begin > end) {
      return 0;
    }
    auto cnt = 0;
    auto begin_c = word[begin];
    int pos_now = begin;
    for(int i = 0; i < k;i++) {
      pos_now = pos[]
    }
  }
 public:
  int countCompleteSubstrings(std::string word, int k) {
    int ans = 0;
    auto word_begin = 0;
    cnt_.emplace_back(26,0);
    for(int  i = 0 ; i < word.size();i++) {
      pos[word[i]-'a'].emplace_back(i);
      auto cnt = cnt_.back();
      cnt[word[i]-'a']++;
    }
    for(int i = 1 ; i < word.size();i++) {
      if(abs(word[i]-word[i-1])>2) {
        ans+=handleSubstr(word,word_begin,i,k);
        word_begin = i;
      }
    }
    ans+=handleSubstr(word,word_begin,int(word.size()),k);
    return ans;
  }
};