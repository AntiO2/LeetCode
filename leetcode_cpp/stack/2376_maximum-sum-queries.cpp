/**
 * @author Anti
 * @date 2023-11-17
 * @see https://leetcode.cn/problems/maximum-sum-queries
 */

#include <numeric>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  std::vector<int> maximumSumQueries(std::vector<int>& nums1,
                                     std::vector<int>& nums2,
                                     std::vector<std::vector<int>>& queries) {
    std::vector<std::pair<int, int>> nums;

    for (int i = 0; i < nums1.size(); ++i) {
      nums.emplace_back(nums1[i], nums2[i]);
    }
    std::sort(nums.begin(), nums.end(), [](const auto& p1, const auto& p2) {
      return p1.first > p2.first;
    });
    auto query_number = queries.size();
    std::vector<int> ans(query_number, -1);
    std::vector<int> query_index(query_number);
    std::iota(query_index.begin(), query_index.end(), 0);
    std::sort(query_index.begin(), query_index.end(),
              [&queries](const auto& i1, const auto& i2) {
                return queries[i1][0] > queries[i2][0];
              });
    std::vector<std::pair<int, int>> stack;
    auto num_iter = nums.begin();
    for (auto query_i : query_index) {
      auto query = queries[query_i];
      auto min_x = query[0], min_y = query[1];
      while (num_iter != nums.end() && num_iter->first >= min_x) {
        // 可以尝试选择该元素。
        int back = stack.size() - 1;
        if (back >= 0 && num_iter->second <= stack[back].first) {
          // y比之前小
          ++num_iter;
          continue;
        }
        auto sum = num_iter->first + num_iter->second;
        while (back >= 0) {
          if (stack[back].second <= sum) {
            --back;
            stack.pop_back();
          } else {
            break;
          }
        }
        stack.emplace_back(num_iter->second, sum);
        ++num_iter;
      }
      auto new_pair = std::make_pair(min_y, 0);
      auto first_y = std::lower_bound(
          stack.begin(), stack.end(), new_pair,
          [](const auto& s1, const auto& s2) { return s1.first < s2.first; });
      if (first_y != stack.end()) {
        ans[query_i] = (*first_y).second;
      }
    }
    return ans;
  }
};  // maximum-sum-queries

TEST(test2376, SAMPLE1) {
  Solution sol;
  std::vector nums1{4, 3, 1, 2};
  std::vector nums2{2, 4, 9, 5};
  std::vector<std::vector<int>> queries{std::vector{4, 1}, std::vector{1, 3},
                                        std::vector{2, 5}};
  std::vector ans{6, 10, 7};
  EXPECT_EQ(sol.maximumSumQueries(nums1, nums2, queries), ans);
}

TEST(test2376, SAMPLE2) {
  Solution sol;
  std::vector nums1{3, 2, 5};
  std::vector nums2{2, 3, 4};
  std::vector<std::vector<int>> queries{std::vector{4, 4}, std::vector{3, 2},
                                        std::vector{1, 1}};
  std::vector ans{9, 9, 9};
  EXPECT_EQ(sol.maximumSumQueries(nums1, nums2, queries), ans);
}
TEST(test2376, SAMPLE3) {
  Solution sol;
  std::vector nums1{72, 44};
  std::vector nums2{60, 86};
  std::vector<std::vector<int>> queries{std::vector{33, 44}};
  std::vector ans{9, 9, 9};
  EXPECT_EQ(sol.maximumSumQueries(nums1, nums2, queries), ans);
}