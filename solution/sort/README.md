## 快速排序

写快排的双指针一直拿不准边界条件...

感觉CLRS的写法好多了。

CLRS上的写法是从左向右，快指针如果发现一个大于分界值的点，就和小于分界值区的指针交换。

```cpp
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
```