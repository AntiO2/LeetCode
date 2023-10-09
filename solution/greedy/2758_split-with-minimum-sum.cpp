//
// Created by Anti on 2023/10/9.
//
#include <list>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
public:
    int splitNum(int num) {
        short cnt[10];
        memset(cnt,0,sizeof (cnt));
        while(num) {
            ++cnt[num%10]; // 统计数字出现次数
            num/=10;
        }
        bool book = 0; // book = 0, 分配给第一个数字，book=1,分配给第二个数字
        int pow = 1;
        int ans = 0;
        for(int i = 9; i; --i) {
            for(int j = 0; j < cnt[i]; ++j) {
                ans+=pow*i;
                if(book) {
                    book = false;
                    pow*=10;
                } else {
                    book = true;
                }
            }
        }
        return ans;
    }
};

TEST(test2758,SAMPLE1) {
    Solution s;
    EXPECT_EQ(s.splitNum(4325),59);
}

TEST(test2758,SAMPLE2) {
    Solution s;
    EXPECT_EQ(s.splitNum(687),75);
}
