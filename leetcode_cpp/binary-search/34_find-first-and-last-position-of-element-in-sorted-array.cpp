/**
 * @author Anti
 * @date 2023/11/7
 * @see
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

template <typename _ForwardIterator, typename _Tp, typename _Compare>
_ForwardIterator anti_lower_bound(_ForwardIterator first, _ForwardIterator last,
                                  const _Tp& __val, _Compare __comp) {
  // 检查概念
  // concept requirements
  __glibcxx_function_requires(_ForwardIteratorConcept<_ForwardIterator>)
      __glibcxx_function_requires(
          _BinaryPredicateConcept<
              _Compare, _Tp,
              typename iterator_traits<_ForwardIterator>::value_type>) auto
          len = std::distance(first, last);
  auto begin = first;
  while (len > 0) {

    auto half = len / 2;
    auto mid = first;

    std::advance(mid, half);  // 获得中心点位置。
                              // LOG_INFO("%s",
    // fmt::format("l:{} r: {} mid: {}", std::distance(begin, first),
    //             std::distance(begin, first + len),
    //             std::distance(begin, mid))
    //     .c_str());
    if (__comp(*mid, __val)) {
      first = mid + 1;
      len = len - half - 1;
    } else {
      len = half;
    }
  }
  return first;
}

template <typename _ForwardIterator, typename _Tp, typename _Compare>
_ForwardIterator anti_upper_bound(_ForwardIterator first, _ForwardIterator last,
                                  const _Tp& __val, _Compare __comp) {
  // 检查概念
  // concept requirements
  __glibcxx_function_requires(_ForwardIteratorConcept<_ForwardIterator>)
      __glibcxx_function_requires(
          _BinaryPredicateConcept<
              _Compare, _Tp,
              typename iterator_traits<_ForwardIterator>::value_type>) auto
          len = std::distance(first, last);
  auto begin = first;
  while (len > 0) {

    auto half = len / 2;
    auto mid = first;

    std::advance(mid, half);  // 获得中心点位置。
                              // LOG_INFO("%s",
    // fmt::format("l:{} r: {} mid: {}", std::distance(begin, first),
    //             std::distance(begin, first + len),
    //             std::distance(begin, mid))
    //     .c_str());
    if (__comp(__val, *mid)) {
      len = half;
    } else {
      first = mid + 1;
      len = len - half - 1;
    }
  }
  return first;
}

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    auto lower_iter = lower_bound(nums.begin(), nums.end(), target);
    if (lower_iter == nums.end() || *lower_iter != target) {
      return {-1, -1};
    }
    auto upper_iter = upper_bound(nums.begin(), nums.end(), target);
    return std::vector<int>{
        static_cast<int>(std::distance(nums.begin(), lower_iter)),
        static_cast<int>(std::distance(nums.begin(), upper_iter)) - 1};
  }
  std::vector<int> antiSearchRange(std::vector<int>& nums, int target) {
    auto lower_iter =
        anti_lower_bound(nums.begin(), nums.end(), target, std::less<int>{});
    if (lower_iter == nums.end() || *lower_iter != target) {
      return {-1, -1};
    }
    auto upper_iter =
        anti_upper_bound(nums.begin(), nums.end(), target, std::less<int>{});
    return std::vector<int>{
        static_cast<int>(std::distance(nums.begin(), lower_iter)),
        static_cast<int>(std::distance(nums.begin(), upper_iter)) - 1};
  }
};

TEST(LOWER_BOUND, S1) {
  std::vector nums{1, 3, 5, 7, 9, 9, 11};
  auto iter = anti_lower_bound(nums.begin(), nums.end(), 8, std::less<int>{});
  LOG_INFO("%d %lld", *iter, std::distance(nums.begin(), iter));
}
TEST(UPPER_BOUND, S1) {
  std::vector nums{1, 3, 5, 7, 9, 9, 11};
  auto iter = anti_upper_bound(nums.begin(), nums.end(), 9, std::less<int>{});
  LOG_INFO("%d %lld", *iter, std::distance(nums.begin(), iter));
}