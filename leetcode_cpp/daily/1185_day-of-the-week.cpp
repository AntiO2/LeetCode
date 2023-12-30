/**
 * @author Anti
 * @date 2023-12-30
 * @see https://codeforces.com/contest/day-of-the-week/problem/1185
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::string dayOfTheWeek(int day, int month, int year) {
    std::vector<std::string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int days = 365 * (year - 1971) + (year - 1969) / 4;
    for (int i = 0; i < month - 1; ++i) {
      days += monthDays[i];
    }
    if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) {
      days += 1;
    }
    days += day;
    return weekdays[(days + 4) % 7];
  }
};