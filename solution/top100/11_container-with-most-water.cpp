//
// Created by Anti on 2023/9/7.
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0;
        int r = int(height.size()) - 1;
        int ans = 0;
        auto l_height = height.at(l);
        auto r_height = height.at(r);
        while(l < r) {
            // LOG_INFO("l:%d r:%d",l,r);
            if(l_height < r_height) {
                ans = std::max(ans, int(l_height * (r - l)));
                l_height = height.at(++l);
            } else {
                ans = std::max(ans, int(r_height * (r - l)));
                r_height = height.at(--r);
            }
        }
        return ans;
    }
};

class test: public testing::Test {
public:
    Solution s;
    std::vector<int> putin;
    int ans{};
protected:
    void SetUp() override {
        Test::SetUp();
    }

    void TearDown() override {
        Test::TearDown();
    }
};

TEST_F(test,SAMPLE1) {
    ans = 49;
    putin = {1,8,6,2,5,4,8,3,7};
    EXPECT_EQ(s.maxArea(putin), ans);
}

TEST_F(test,SAMPLE2) {
    ans = 1;
    putin = {1,1};
    EXPECT_EQ(s.maxArea(putin), ans);
}