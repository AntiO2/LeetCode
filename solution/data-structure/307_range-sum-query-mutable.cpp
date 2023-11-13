/**
 * @author Anti
 * @date 2023/11/13
 * @see https://leetcode.cn/problems/range-sum-query-mutable
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class NumArray {
 private:
  std::vector<int> tree_;  // 树状数组
  inline int lowbit(int x) { return x & (-x); }
  int get_prev_sum(int x) {
    int sum = 0;
    for (int pos = x; pos; pos -= lowbit(pos)) {
      sum += tree_[pos];
    }
    return sum;
  }
  void update_helper(int index, int val) {
    for (int pos = index; pos < tree_.size(); pos += lowbit(pos)) {
      tree_[pos] += val;
    }
  }

 public:
  NumArray(std::vector<int>& nums) : tree_(nums.size() + 1, 0) {
    for (int i = 0; i < nums.size(); ++i) {
      update_helper(i + 1, nums[i]);
    }
  }

  void update(int index, int val) {
    auto prev = sumRange(index, index);
    auto delta = val - prev;
    update_helper(index + 1, delta);
  }

  int sumRange(int left, int right) {
    return get_prev_sum(right + 1) - get_prev_sum(left);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
TEST(test307, S1) {
  std::vector nums{1, 3, 5};
  NumArray n(nums);
  EXPECT_EQ(n.sumRange(0, 2), 9);
  n.update(1, 2);                  // nums = [1,2,5]
  EXPECT_EQ(n.sumRange(0, 2), 8);  // 返回 1 + 2 + 5 = 8
}