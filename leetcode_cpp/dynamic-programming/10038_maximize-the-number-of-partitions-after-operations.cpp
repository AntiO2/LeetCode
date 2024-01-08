/**
 * @author Anti
 * @date 2024-01-08
 * @see
 * https://leetcode.cn/problems/maximize-the-number-of-partitions-after-operations
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
  using mask_t = std::bitset<26>;
  using status_t = std::pair<mask_t, int>;
 private:
  /**
   * 维护每个状态对应子串数量的最大值
   * @param map 状态集合
   * @param mask
   * @param ans
   */
  static void update_status(std::unordered_map<mask_t,int> &map, const mask_t& mask, int ans) {
    auto iter = map.find(mask);
    if(iter==map.end()) {
      map[mask] = ans;
      return;
    }
    (*iter).second = std::max((*iter).second,ans);
  }

  /**
   * 从旧状态，添加一个新的字母c。维护状态集合
   * @param old_mask 旧状态
   * @param i 添加的新字母
   * @param old_cnt 旧状态所包含的子串数量
   * @param map 状态集合
   * @param k
   */
  static void update_map(const mask_t&old_mask, int i, int old_cnt, std::unordered_map<mask_t,int> &map,int k) {
    if(old_mask.test(i)) {
      // 旧状态已经包含了该字母
      update_status(map, old_mask, old_cnt);
    }
    else {
      if(old_mask.count()==k) {
        // 旧状态已经包含了k个不同字母
        mask_t new_mask;
        new_mask.set(i);
        // 开始新分割
        update_status(map, new_mask, old_cnt+1);
      } else {
        // 旧状态不包含k个不同字母
        // 在原有前缀上改变字母
        mask_t new_mask(old_mask);
        new_mask.set(i);
        update_status(map, new_mask, old_cnt);
      }
    }
  }
 public:
  int maxPartitionsAfterOperations(std::string s, int k) {
    status_t  not_modify;
    not_modify.second = 1; // 注意初始情况下，也包含一个长度为0的分割。
    std::unordered_map<mask_t,int> modified;
    for(auto character:s) {
      std::unordered_map<mask_t, int> new_map;
      auto index = character - 'a';
      status_t new_not_modify;
      if(not_modify.first.test(index)) {
        // 如果前缀已经出现该位置的字母，not modify不变
        new_not_modify = not_modify;
      } else {
        // 如果前缀没有出现该位置的字母，并且该位置不修改。
        if(not_modify.first.count()==k) {
          new_not_modify.first.set(index);
          new_not_modify.second = not_modify.second + 1;// 增加一次分割
        } else {
          new_not_modify = not_modify;
          new_not_modify.first.set(index);// 未满k, 不增加分割
        }
      }

      // 如果要从前一个位置not modify开始，对该位置进行修改。
      for(int i = 0; i < 26;i++) {
        update_map(not_modify.first, i, not_modify.second, new_map, k);
      }

      // 从前一个位置修改过的状态转移，该位置不进行修改
      for(auto&[mask,count]:modified) {
        update_map(mask, index, count, new_map, k);
      }

      not_modify = std::move(new_not_modify); //维护不需要修改的状态
      modified= std::move(new_map); // 已经进行过一次修改后的状态集合
    }
    // 统计结果
    auto ans = not_modify.second;
    for(auto&[mask, count]:modified) {
      ans= std::max(ans,count);
    }
    return ans;
  }
};  // maximize-the-number-of-partitions-after-operations