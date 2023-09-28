# 关于Lambda函数的杂谈

今天做[2251. 花期内花的数目 - 力扣（LeetCode）](https://leetcode.cn/problems/number-of-flowers-in-full-bloom/description/)， 看到题目描述和数据范围很容易想到离散化 + 离线查询。



然后写了一个版本。算起来时间复杂度应该是没问题的。

时间复杂度应该是
$$
\begin{aligned}
\Omicron (&mlogm&&	[对people进行排序]\\
+&nlogn&&		[对flower进行差分数组维护]\\
+&nlogn&&[遍历一次map（差分数组）])
\end{aligned}
$$
其中m和n的规模都是$5*10^4$,但是第一次代码提交上去就是超时了。

```c++
#include <numeric>
class Solution {
private:
    std::map<int,int> cnt; // map是有序的
    std::vector<int> ans;
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers, std::vector<int>& people) {
        auto num = people.size();
        std::vector<int> index(num);
        ans.resize(num);
        std::iota(index.begin(),index.end(),0);
        std::sort(index.begin(),index.end(),[people](const int&a,const int b) {
            return people[a] < people[b];
        }); // index指示people从小到大的顺序
        for(const auto&flower: flowers) {
            cnt[flower[0]]++;
            cnt[flower[1] + 1] --;
        }
        auto iter = cnt.begin();
        int current  = 0;
        for(const auto &i:index) {
            while(iter!=cnt.end()&& iter->first <= people[i]) {
                current+=iter->second;
                ++iter;
            }
            ans[i] = current;
        }
        return ans;
    }
};
```





后面检查，才发现是

```c++
        std::sort(index.begin(),index.end(),[people](const int&a,const int b) {
            return people[a] < people[b];
        });
```

的问题。

lambda捕获时有值捕获，引用捕获。

这里进行了值捕获，相当于在排序时，每次比较都要创建一个长度为$5*10^4$的临时数组，拷贝people的值。

如果要进行隐式值捕获，还可以通过`[=]`的形式，比如`std::find_if(people.begin(),people.end(),[=](int& a) {return a==ans[0];});`(之前只用过`[&]`进行捕获)。

同时，值捕获和引用捕获可以同时使用，但是不能同时在隐式使用中使用。

也就是说,`[=,&]`是不被允许的。但是像`[&,a,b]`,`[=,&a,&b]`这种引用捕获列表是被允许的。

比如

```c++
auto a = std::vector<int>{0,1,2,3,4,5};
auto b = std::vector<int>{0,1,2,3,4,5};
std::for_each(a.begin(),a.end(),[=](int i)mutable {
    b[i]++;
});
for(auto &x:b) {
    std::cout<<x<<" ";
}
```

输出`0 1 2 3 4 5 `,原数组未被改变。

```c++
std::for_each(a.begin(),a.end(),[=,&b](int i)mutable {
    b[i]++;
});
```

输出`1 2 3 4 5 6  `, 单独对b进行引用捕获。

```c++
std::for_each(a.begin(),a.end(),[&,b](int i)mutable {
    b[i]++;
});
```

单独对b进行值捕获，输出`0 1 2 3 4 5 `



所以话说回来，改成

```c++
std::sort(index.begin(),index.end(),[&people](const int&a,const int &b) {
    return people[a] < people[b];
});
```

200ms通过了。