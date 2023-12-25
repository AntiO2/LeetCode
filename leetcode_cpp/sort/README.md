# 排序

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

## 线性时间排序

### 计数排序

统计输入为一串**整数**， 然后通过一个新的数组输出。

### 桶排序

桶排序和计数排序不同，统计的是`[0,1)`上均匀分布的一连串小数。

通过将`[0,1)`均匀分割为n个桶，将输入分割。

然后对每个桶使用插入排序。

期望运行时间是$\Theta(n)$。

但是也很好想，如果输入真的很不均匀，比如分了10个桶，但是输入全在`[0,0.1]`,导致全分到第一个桶上，就退化成原始插入排序了。

### 基数排序

[1.10 基数排序 | 菜鸟教程 (runoob.com)](https://www.runoob.com/w3cnote/radix-sort.html)

简单来说，就是先排低权重的位，再（所有数一起）排高权重的位。在所有排序过程中，都要保证**稳定性**

这里的权重不止纯数字，还能像日期排序，日、月、年这样子排。

### 总结

为什么上面三个排序能突破决策树$nlogn$的下界呢？因为都应用了天然的顺序。

1. 对于计数排序，记录的下标就已经是从小到大的了。
2. 对于桶排序，下标是一段范围，而这些范围都是从小到大的。
3. 对于基数排序，权重是从小到大的。