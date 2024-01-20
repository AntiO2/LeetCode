/**
 * @author Anti
 * @date 2024-01-15
 * @see https://www.codewars.com/kata/5259b20d6021e9e14c0010d4/train/cpp
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

std::string reverse_words(std::string str)
{
  auto begin = str.begin();
  for(auto i = str.begin();i !=str.end();i++) {
    if(*i==' ') {
      std::reverse(begin,i);
      begin = std::next(i);
    }
  }
  std::reverse(begin,str.end());
  return str;
}
TEST(RW1,T1) {
  reverse_words("ab cd ef gh");
}