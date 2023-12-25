/**
 * @author Anti
 * @date 2023/11/9
 * @see https://leetcode.cn/problems/sort
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
namespace anti {
template <typename T>
size_t sort_partition(std::vector<T>& v, size_t left, size_t right);
template <typename T>
void sort(std::vector<T>& v, size_t left, size_t right);
template <typename T>
void sort(std::vector<T>& v);

template <typename T>
size_t sort_partition(std::vector<T>& v, size_t left, size_t right) {
  auto j = left;
  auto i = left - 1;  // i 是 小于 x 的 左边一个
  T x = v[right];
  while (j <= right - 1) {
    if (v[j] <= x) {
      std::swap(v[++i], v[j]);
    }
    ++j;
  }
  // 此时[left,i] 都小于等于x, [i+1, right - 1]都大于x
  std::swap(v[++i], v[j]);
  return i;  // i 此时是哨兵值（x）
}
template <typename T>
void sort(std::vector<T>& v, size_t left, size_t right) {
  if (left >= right) {
    return;
  }
  auto mid = sort_partition(v, left, right);
  sort(v, left, mid - 1);
  sort(v, mid + 1, right);
}
template <typename T>
void sort(std::vector<T>& v) {
  sort<T>(v, 0, v.size() - 1);
}

}  // namespace anti

TEST(testquick, SAMPLE1) {
  std::vector nums{1, 2, 3, 9, 7, 4, 2};
  anti::sort(nums);
  for (auto num : nums) {
    LOG_INFO("%d", num);
  }
}

TEST(testquick, SAMPLE2) {
  std::vector nums{1};
  anti::sort(nums);
  for (auto num : nums) {
    LOG_INFO("%d", num);
  }
}