# [LeetCode] 2512 字符串统计 | Modern C++

[2512. 奖励最顶尖的 K 名学生 - 力扣（LeetCode）](https://leetcode.cn/problems/reward-top-k-students/description/?envType=daily-question&envId=2023-10-11)

## 题目描述

给出字符串，如果某个单词存在于某个特定字符串列表，就进行加减分操作。最后进行排序选出前K个。



实现起来很简单，但是今天主要学习题解看到的Modern C++

## 学

[参考题解](https://leetcode.cn/problems/reward-top-k-students/solutions/2478393/wei-yun-suan-ji-qiao-jiang-idya-ru-di-we-pqho/)

代码

```c++
#include <algorithm>
#include <numeric>
#include <ranges>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k) {
        unordered_set pos(positive_feedback.begin(), positive_feedback.end()), neg(negative_feedback.begin(), negative_feedback.end());
        vector score(student_id.size(), 0l);
        ranges::transform(
                report, student_id, score.begin(), [](long sc, unsigned id) { return -(sc << 32 | id); }, [&](auto &&s) { istringstream ss(s);
                return accumulate(istream_iterator<string>(ss), {}, 0l
                            , [&](auto a, auto&& s) { return a + pos.count(s) * 3 - neg.count(s); }); }, negate{});
        ranges::partial_sort(score, score.begin() + k);
        return {score.begin(), score.begin() + k};
    }
};
```



在算出score后，进行从高到低排序。如果score相同，则id从小到大排序。

所以他拼一个64位数字（假设为k），前32位score，后32位负id，最后将k从大到小排序获得结果。

如果先将k取负，最后结果少一个取负步骤。

## 自动推导

[Deduction Guides (since C++17)-CSDN博客](https://blog.csdn.net/weixin_40539125/article/details/106044614)

## std::ranges::transform

参考[std::ranges::transform, std::ranges::unary_transform_result, std::ranges::binary_transform_result - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/ranges/transform)

这里使用了

```c++
template< ranges::input_range R1,
          ranges::input_range R2,
          std::weakly_incrementable O,
          std::copy_constructible F,
          class Proj1 = std::identity, class Proj2 = std::identity >
requires std::indirectly_writable<O,
             std::indirect_result_t<F&,
                 std::projected<ranges::iterator_t<R1>, Proj1>,
                 std::projected<ranges::iterator_t<R2>, Proj2>>>
constexpr binary_transform_result<ranges::borrowed_iterator_t<R1>,
                                  ranges::borrowed_iterator_t<R2>, O>
    transform( R1&& r1, R2&& r2, O result, F binary_op,
               Proj1 proj1 = {}, Proj2 proj2 = {} );
```



| 参数          | 描述                                          | 在题解中的使用                                               |
| ------------- | --------------------------------------------- | ------------------------------------------------------------ |
| r1            | 要变换的第一个元素范围                        | report                                                       |
| r2            | 要变换的第二个元素范围                        | student_id                                                   |
| result        | 目标范围的开头，可能等于 `first1` 或 `first2` | score.begin()                                                |
| op, binary_op | 应用于投影element(s)的操作                    | ` [](long sc, unsigned id) { return -(sc << 32 |id); }`      |
| proj1         | 应用于第一个范围中的元素的投影                | `[&](auto &&s) { istringstream ss(s); return accumulate(istream_iterator<string>(ss), {}, 0l             , [&](auto a, auto&& s) { return a + pos.count(s) * 3 - neg.count(s); }); }` |
| proj2         | 应用于第二个范围中的元素的投影。              | negate{}                                                     |

`report` 通过proj1转化。

首先生成一个输入字符串流`stringstream ss(s)`

返回`accumulate(istream_iterator<string>(ss), {}, 0l             , [&](auto a, auto&& s) { return a + pos.count(s) * 3 - neg.count(s); }); `



`student_id`先通过`  negate{}`取负。



最后两个投影后的结果通过lambda函数`` [](long sc, unsigned id) { return -(sc << 32 |id); }` ` 存储到score中

## accumulate

[std::accumulate - C++中文 - API参考文档 (apiref.com)](https://www.apiref.com/cpp-zh/cpp/algorithm/accumulate.html)

| 参数        |                                                              |                                                              | 作用                         |
| ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------- |
| first, last | `istream_iterator<string>(ss), {}`                           | 要求和的元素范围                                             | 迭代器                       |
| init        | 0l                                                           | 和的初值                                                     | 当前分数值                   |
| op          | `[&](auto a, auto&& s) { return a + pos.count(s) * 3 - neg.count(s); })` | 被使用的二元函数对象。接收当前积累值 `a` （初始化为 `init` ）和当前元素 `b` 的二元运算符。 该函数的签名应当等价于： Ret fun(const Type1 &a, const Type2 &b);签名中并不需要有 const &。 类型 Type1 必须使得 T 类型的对象能隐式转换到 Type1 。类型 Type2 必须使得 InputIt 类型的对象能在解引用后隐式转换到 Type2 。 类型 Ret 必须使得 T 类型对象能被赋 Ret 类型值。 | a是累计的分数，s是当前的单词 |



## 列表初始化

```c++
TEST(test2512, SAMPLE3) {
    string s = "this student is studious";
    istringstream ss(s);
    std::for_each(istream_iterator<string>(ss), {}, [](auto &s) {
        cout << s << endl;
    });
}
```

在函数参数里构造迭代器，第二个参数自动推导为end()