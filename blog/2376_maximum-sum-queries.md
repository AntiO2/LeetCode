# [2736. 最大和查询 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-sum-queries/description/?envType=daily-question&envId=2023-11-17)

> 给你两个长度为 `n` 、下标从 **0** 开始的整数数组 `nums1` 和 `nums2` ，另给你一个下标从 **1** 开始的二维数组 `queries` ，其中 `queries[i] = [xi, yi]` 。
>
> 对于第 `i` 个查询，在所有满足 `nums1[j] >= xi` 且 `nums2[j] >= yi` 的下标 `j` `(0 <= j < n)` 中，找出 `nums1[j] + nums2[j]` 的 **最大值** ，如果不存在满足条件的 `j` 则返回 **-1** 。
>
> 返回数组 `answer` *，*其中 `answer[i]` 是第 `i` 个查询的答案。

因为数组长$10^5$, 有$10^5$ 个查询，直接遍历肯定TLE.

如果只有一个数组，（忽略y）容易想到通过x的值对与`max(nums1)`进行比较。

> Sort (x, y) tuples and queries by x-coordinate descending. Don’t forget to index queries before sorting so that you can answer them in the correct order.

首先将`nums1,nums2` 按照x降序排列。

> Before answering a query (min_x, min_y), add all (x, y) pairs with x >= min_x to some data structure.

当我们已经将查询按照X从大到小排。所有按照X过滤的元组是可以被过滤的。

> Use a monotone descending map to store (y, x + y) pairs. A monotone map has ascending keys and descending values. When inserting a pair (y, x + y), remove all pairs (y', x' + y') with y' < y and x' + y' <= x + y.

当处理一个新的查询时，如果新查询的min_x下降了，说明有新的nums对能加入进来，但是新的`nums.x`肯定是比之前都小的（因为前面已将x降序排列）。如果新的`nums.[y]`还比前面更小，那直接不用看了。和肯定比之前小还不一定选的上。

维护一个单调栈，此时我们考虑的新`nums.y`一定比之前的更加大。但是大就是好吗？因为新的`nums.x`一定不比之前大，所以新的`nums.x+nums.y`可能比之前的更小。

同样的，如果`nums.x+nums.y`比之前的更大，那么没有必要保留之前的数组对。

所以有以下三种情况

- 新的`nums.y` 更小，没有任何可能它是有用的。
- 新的`nums.y`更大
  - 如果新的`x+y`大于之前的`x+y`,那么之前的没有必要保留
  - 之前的`old x+y` 更大，需要保留。所以留下来的都是更大的，导致`x+y`单调递减

所以我们获得了按照`y`递增，`x+y`递减的单调栈。



如何找到某个查询的答案呢？

我们想要`x+y`尽可能大，就需要尽可能往维护的单调栈前面找（因为`x+y`递减），但是因为`y`递增。所以需要二分查找，找到第一个`y>=query.min_y`的地方。





**题外话**

感觉被

`auto back = stack.size() - 1;`这个坑过无数次了。

