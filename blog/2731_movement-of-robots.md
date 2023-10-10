# [LeetCode] 2731_movement-of-robots

[2731. 移动机器人 - 力扣（LeetCode）](https://leetcode.cn/problems/movement-of-robots/description/?envType=daily-question&envId=2023-10-10)

## 思路

> 当两个机器人相撞时，它们开始沿着原本相反的方向移动。
>
> 
>
> - 对于坐标在 `i` 和 `j` 的两个机器人，`(i,j)` 和 `(j,i)` 视为相同的坐标对。也就是说，机器人视为无差别的。
> - 当机器人相撞时，它们 **立即改变** 它们的前进方向，这个过程不消耗任何时间。
> - 当两个机器人在同一时刻占据相同的位置时，就会相撞。
>   - 例如，如果一个机器人位于位置 0 并往右移动，另一个机器人位于位置 2 并往左移动，下一秒，它们都将占据位置 1，并改变方向。再下一秒钟后，第一个机器人位于位置 0 并往左移动，而另一个机器人位于位置 2 并往右移动。
>   - 例如，如果一个机器人位于位置 0 并往右移动，另一个机器人位于位置 1 并往左移动，下一秒，第一个机器人位于位置 0 并往左行驶，而另一个机器人位于位置 1 并往右移动。

因为机器人之间是无差别的，所以`i`和`j`两个机器人是等效的。假如不存在碰撞规则， 结果也是不变的。

![Screenshot_2023-10-10-23-40-06-888_com.jideos.jno](https://antio2-1258695065.cos.ap-chengdu.myqcloud.com/img/blogScreenshot_2023-10-10-23-40-06-888_com.jideos.jno.jpg)

通过初始位置，方向，时间的数组，可以得到最后所以机器人所在位置的数组d。



接下来就是如何算两两之间的位置和，因为$n \lt 10^5$, $O(n^2)$ 的直接算是不行的。



$ans = \sum\limits_{i=1}^{n-1}\sum\limits_{j=i+1}^{n}abs(d_i-d_j)$

如果将d从小到大排序，那么$abs(d_i-d_j)\equiv d_j-d_i$

$ans = \sum\limits_{i=1}^{n-1}\sum\limits_{j=i+1}^{n}d_j-d_i=\sum\limits_{j=1}^{n} (j-1)*d_j-\sum\limits_{i=1}^{n}(n-i)*d_i$ (计算i和j的出现次数)

如果下标从0开始，就是

$ans =\sum\limits_{j=0}^{n-1} j*d_j-\sum\limits_{i=0}^{n-1}(n-i-1)*d_i=\sum\limits_{i=0}^{n-1}(2*i+1-n)*d_i$

```c++
class Solution {
public:
    int sumDistance(std::vector<int> &nums, std::string s, int d) {
        constexpr int mod = 1e9 + 7;
        long long ans = 0;
        int l = int(nums.size());
        std::vector<long long> final(l);
        for (int i = 0; i < l; i++) {
            if (s[i] == 'R') {
                final[i] = nums[i] + d;
            } else {
                final[i] = nums[i] - d;
            }
        }
        std::sort(final.begin(), final.end());
        for (int i = 0; i < l; ++i) {
            ans = (ans + (2 * i - l + 1) * final[i]) % mod;
        }
        return int(ans);
    }
};
```

优化：

（下标从1开始）

$ans =\sum\limits_{i=1}^{n-1}\sum\limits_{j=i+1}^{n}d_j-d_i=\sum\limits_{i=2}^{n}((i-1)*d_i-\sum\limits_{j=1}^{i-1}d_j)$，其中可以通过前缀和维护第二个项。

证明思路大概是提出第一个公式中第一个项的内部求和符号，然后数学归纳法交换第二个符号。

放在这道题的意义就是：假设计算第i个机器人时，右端点$d_i$ 出现$(i-1)$ 次，减去左端点值的和得到以第i个机器人为右侧的距离和。其中左端点值的和通过前缀和维护。