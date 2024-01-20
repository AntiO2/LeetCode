/**
 * @author Anti
 * @date 2024-01-20
 * @see https://leetcode.cn/problems/split-strings-by-separator
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<std::string> splitWordsBySeparator(std::vector<std::string>& words, char separator) {
        std::vector<std::string>  ans;
        for(auto&word:words) {
          size_t begin = 0;
          size_t now = 0;
          size_t l = word.length();
          while (now < l) {
              if(word[now]==separator) {
                if(begin < now) {
                  ans.emplace_back(word.substr(begin, now-begin));
                }
               begin = now+1;
              }
              now++;
            }
          if(begin < now) {
            ans.emplace_back(word.substr(begin, now - begin));
          }
        }
        return ans;
  }
};  // split-strings-by-separator

TEST(test2788, SAMPLE1) {
  Solution sol;
}

TEST(test2788, SAMPLE2) {
  Solution sol;
}