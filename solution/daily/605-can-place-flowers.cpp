//
// Created by Anti on 2023/9/29.
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"
#include <list>

class Solution {

public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
        int ans = 0;
        int iter = 0;// 查看当前能否种花。
        const int num = (int) flowerbed.size();
        while (iter < num - 1) {
            if (flowerbed[iter]) {
                iter += 2;
            } else {
                if (flowerbed[iter + 1]) {
                    iter += 3;
                } else {
                    ++ans;
                    iter += 2;
                }
            }
        }
        if (iter == num - 1 && !flowerbed[iter]) {
            if (num == 1) {
                ++ans;
            } else if (!flowerbed[iter - 1]) {
                ++ans;
            }
        }
        return ans >= n;
    }
};

TEST(test605, SAMPLE1) {
    Solution s;
    std::vector<int> fb{1, 0, 0, 0, 1};
    int n = 1;
    EXPECT_EQ(s.canPlaceFlowers(fb, n), true);
}


TEST(test605, SAMPLE2) {
    Solution s;
    std::vector<int> fb{1, 0, 0, 0, 1};
    int n = 2;
    EXPECT_EQ(s.canPlaceFlowers(fb, n), false);
}

TEST(test605, SAMPLE3) {
    Solution s;
    std::vector<int> fb{0};
    int n = 1;
    EXPECT_EQ(s.canPlaceFlowers(fb, n), true);
}