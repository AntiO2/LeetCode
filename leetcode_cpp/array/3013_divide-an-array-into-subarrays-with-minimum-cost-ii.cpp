/**
 * @author Anti
 * @date 2024-01-20
 * @see
 * https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-ii
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <queue>
class Window {
 private:
  long long sum_{0};
  size_t k_{0};
  std::priority_queue<int> smaller; // 较小的部分，一定等于m。
  std::priority_queue<int,std::vector<int>,std::greater<>> bigger; // 滑动窗口中较大的部分。
  std::unordered_map<int,int> mark_delete_;
  size_t smaller_cnt{0};
  template <class T>
  auto maintain(T &pq) ->void {
    while (!pq.empty()) {
      auto iter = mark_delete_.find(pq.top());
      if (iter == mark_delete_.end()) {
        return;
      }
      if (--(iter->second) == 0) {
        mark_delete_.erase(iter);
      }
      pq.pop();
    }
  }
 public:
  Window(size_t k, std::vector<int>::iterator begin,
         std::vector<int>::iterator end,long long &ans, long long sum = 0):
        sum_(sum),k_(k) {
    ans = LONG_LONG_MAX;
    while(begin!=end) {
      add(*begin);
      if(smaller_cnt==k) {
        ans = std::min(ans,sum_ + *std::next(begin));
      }
      begin++;
    }
  }
  auto add(int num) -> void {
    if(smaller_cnt < k_) {
      smaller_cnt++;
      smaller.emplace(num);
      sum_+=num;
      return ;
    }
    // 如果smaller已满,分两种情况。添加到不同堆里面
    if(smaller.top() <= num) {
      bigger.emplace(num);
    } else {
      bigger.emplace(smaller.top());
      sum_-=smaller.top();
      smaller.pop();
      smaller.emplace(num);
      sum_+=num;

      maintain(smaller);
    }
  }
  auto remove(int num) -> void {
    if(num<=smaller.top()) {
      smaller.emplace(bigger.top());
      sum_ = sum_ - num + bigger.top();
      bigger.pop();
      mark_delete_[num]++;
      maintain(smaller);
      maintain(bigger);
    } else {
      mark_delete_[num]++;
      maintain(bigger);
    }
  }
  long long int getSum() const { return sum_; }
};
class Solution {
 public:
  long long minimumCost(std::vector<int>& nums, int k, int dist) {
    long long ans;
    auto w = std::make_unique<Window>(k-2,nums.begin()+1,nums.begin() + dist + 1, ans, nums[0]);
    int n = nums.size();
    for(int i = dist + 1; i < n -1; i++) {
      w->add(nums[i]);
      w->remove(nums[i - dist]);
      if(w->getSum() + nums[i +1] < ans) {
        ans = w->getSum() + nums[i+1];
      }
    }
    return ans;
  }
};  // divide-an-array-into-subarrays-with-minimum-cost-ii

TEST(test100178, SAMPLE1) {
  Solution sol;
  std::vector nums{1,5,3,6};
  EXPECT_EQ(sol.minimumCost(nums, 3, 2),9);
}

TEST(test100178, SAMPLE2) {
  Solution sol;
  std::vector nums{10,1,2,2,2,1};
  EXPECT_EQ(sol.minimumCost(nums, 4, 3), 15);
}