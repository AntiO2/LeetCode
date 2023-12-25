/**
 * @author Anti
 * @date 2023/11/12
 * @see https://leetcode.cn/problems/range-module
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class RangeModule {
 private:
  std::map<int, int> mp;

 public:
  RangeModule() {}

  void addRange(int left, int right) {
    int l = left, r = right;
    // 找到刚好大于等于l的区间
    auto p = mp.lower_bound(left);
    // 合并重合区间
    while (p != mp.end() && p->second <= right) {
      l = std::min(p->second, l);
      r = std::max(p->first, r);
      auto temp = p;
      p++;
      mp.erase(temp->first);
    }
    mp[r] = l;
  }

  bool queryRange(int left, int right) {
    auto iter = mp.lower_bound(left);
    if (iter == mp.end())
      return false;
    if (iter->second <= left && iter->first >= right)
      return true;  // 覆盖整个范围，才返回true
    return false;
  }

  void removeRange(int left, int right) {
    // 找到大于等于left的区间
    auto p = mp.lower_bound(left + 1);
    while (p != mp.end() && p->second <= right) {
      // 左边有可用区间
      if (p->second < left) {
        mp[left] = p->second;
      }
      // 右边有可用区间
      if (p->first > right) {
        mp[p->first] = right;
        break;
      } else {  // 否则全部删除
        auto temp = p;
        p++;
        mp.erase(temp->first);
      }
    }
  }
};