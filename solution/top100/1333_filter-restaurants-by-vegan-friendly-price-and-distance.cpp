//
// Created by Anti on 2023/9/27.
//

#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"

#include <list>
using namespace std;
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        auto end = std::partition(restaurants.begin(), restaurants.end(), [&](const auto &item) {
            return (item[2] || !veganFriendly) && (item[3] <= maxPrice) && item[4] <= maxDistance;
        });
        std::sort(restaurants.begin(), end, [](const auto &item1, const auto &item2) {
            return item1[1] == item2[1] ? item1[0] > item2[0] : item1[1] > item2[1];
        });
        auto num = distance(restaurants.begin(), end);
        auto ans = std::vector<int>{};
        for (auto i = 0; i < num; i++) {
            ans.emplace_back(restaurants[i][0]);
        }
        return std::move(ans);
    }
};

TEST(test1333, SAMPLE1) {
    Solution s;
    auto r = vector<vector<int>>{{1, 4, 1, 40, 10}, {2, 8, 0, 50, 5}, {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1}};
    int v = 1;
    int price = 50;
    int d = 10;
    auto ans = std::vector<int>{3, 1, 5};
    EXPECT_EQ(s.filterRestaurants(r, v, price, d), ans);
}

TEST(test1333, SAMPLE2) {
    Solution s;
}