/**
 * @author Anti
 * @date 2024-01-21
 * @see https://leetcode.cn/problems/sliding-window-median
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

#include <queue>
class Solution {
 private:
  std::map<int,int> mark_delete_;
  std::priority_queue<int,std::vector<int>,std::greater<>> bigger_; // 较大的部分
  std::priority_queue<int> smaller_; // 较小的部分
  size_t smaller_cnt_{0}; // 较小部分个数
  size_t bigger_cnt_{0}; // 较大部分个数
  bool odd_{true};
  auto add(int num) -> void  {
    if(smaller_cnt_==bigger_cnt_) {
      if(smaller_.empty()||num<=smaller_.top()) {
        smaller_cnt_++;
        smaller_.emplace(num);
      } else {
        bigger_cnt_++;
        bigger_.emplace(num);
      }
      return ;
    }
    // 一个状态维护后，永远是smaller_cnt - bigger_cnt <= 1
    if(smaller_.top() < num) {
      bigger_.emplace(num);
      bigger_cnt_++;
    } else {
      smaller_.emplace(num);
      smaller_cnt_++;
    }
  }
  auto remove(int num) -> void {
    if(num<=smaller_.top()) {
      smaller_cnt_--;
      mark_delete_[num]++;
    } else {
      bigger_cnt_--;
      mark_delete_[num]++;
    }
  }
  auto balance() -> void {
    while(!smaller_.empty()) {
      auto iter = mark_delete_.find(smaller_.top());
      if(iter == mark_delete_.end()) {
        break ; // 此时堆顶有效
      }
      smaller_.pop();
      if(--(iter->second)==0) {
        mark_delete_.erase(iter);
      }
    }
    while(!bigger_.empty()) {
      auto iter = mark_delete_.find(bigger_.top());
      if(iter == mark_delete_.end()) {
        break ; // 此时堆顶有效
      }
      bigger_.pop();
      if(--(iter->second)==0) {
        mark_delete_.erase(iter);
      }
    }
    // 此时两个堆的堆顶都有效
    if(smaller_cnt_ + 1 == bigger_cnt_) {
      smaller_.emplace(bigger_.top());
      bigger_.pop();
      smaller_cnt_++;
      bigger_cnt_--;
      // 此时bigger堆顶不一定有效
      while(!bigger_.empty()) {
        auto iter = mark_delete_.find(bigger_.top());
        if(iter == mark_delete_.end()) {
          break ; // 此时堆顶有效
        }
        bigger_.pop();
        if(--(iter->second)==0) {
          mark_delete_.erase(iter);
        }
      }
      return;
    }
    if(smaller_cnt_==bigger_cnt_||smaller_cnt_==bigger_cnt_+1) {
      return;
    }
    if(smaller_cnt_==bigger_cnt_+2) {
      bigger_.emplace(smaller_.top());
      smaller_.pop();
      smaller_cnt_--;
      bigger_cnt_++;
      while(!smaller_.empty()) {
        auto iter = mark_delete_.find(smaller_.top());
        if(iter == mark_delete_.end()) {
          break ; // 此时堆顶有效
        }
        smaller_.pop();
        if(--(iter->second)==0) {
          mark_delete_.erase(iter);
        }
      }
      return;
    }
    assert(false);
  }

  auto get_mid() -> double {
    if(odd_) {
      return smaller_.top();
    }
    return (double)((double)smaller_.top()+(double)bigger_.top()) / 2;
  }
 public:
  std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
    odd_ = k%2;
    std::vector<double> ans;
    for(int i = 0; i < k;i++) {
      add(nums[i]);
      balance();
    }
    ans.emplace_back(get_mid());
    int n = int(nums.size());
    for(int i = k; i < n;i++) {
      add(nums[i]);
      balance();
      remove(nums[i-k]);
      balance();
      ans.emplace_back(get_mid());
    }
    return ans;
  }
};  // sliding-window-median

TEST(test480, SAMPLE1) {
  Solution sol;
  std::vector nums{1,3,-1,-3,5,3,6,7};
  sol.medianSlidingWindow(nums,3);
}

TEST(test480, SAMPLE2) {
  Solution sol;
  std::vector nums{1,2,3,4,2,3,1,4,2};
  sol.medianSlidingWindow(nums,3);
}