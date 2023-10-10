//
// Created by Anti on 2023/9/28.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"
#include <list>
#include <numeric>
class Solution {
private:
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>> &flowers, std::vector<int> &people) {
        std::map<int, int> cnt;// map是有序的
        auto num = people.size();
        std::vector<int> index(num);
        std::vector<int> ans(num);
        std::iota(index.begin(), index.end(), 0);
        std::sort(index.begin(), index.end(), [&people](const int &a, const int &b) {
            return people[a] < people[b];
        });// index指示people从小到大的顺序
        for (const auto &flower: flowers) {
            cnt[flower[0]]++;
            cnt[flower[1] + 1]--;
        }
        auto iter = cnt.begin();
        int current = 0;
        for (const auto &i: index) {
            while (iter != cnt.end() && iter->first <= people[i]) {
                current += iter->second;
                ++iter;
            }
            ans[i] = current;
        }
        return ans;
    }
};

TEST(test2251, SAMPLE1) {
    Solution s;
    auto flowers = std::vector<std::vector<int>>{{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    auto people = std::vector<int>{2, 3, 7, 11};
    auto ans = std::vector<int>{1, 2, 2, 2};
    EXPECT_EQ(s.fullBloomFlowers(flowers, people), ans);
}

TEST(test2251, SAMPLE2) {
    Solution s;
    auto flowers = std::vector<std::vector<int>>{{1, 10}, {3, 3}};
    auto people = std::vector<int>{3, 3, 2};
    auto ans = std::vector<int>{2, 2, 1};
    EXPECT_EQ(s.fullBloomFlowers(flowers, people), ans);
}

TEST(test2251, SAMPLE3) {
    auto a = std::vector<int>{0, 1, 2, 3, 4, 5};
    auto b = std::vector<int>{0, 1, 2, 3, 4, 5};
    std::for_each(a.begin(), a.end(), [&, b](int i) mutable {
        b[i]++;
    });

    std::cout << std::endl;
    for (auto &x: b) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}