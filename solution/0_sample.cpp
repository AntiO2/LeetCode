//
// Created by Anti
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution{};

class test: public testing::Test {
public:
    Solution s;
protected:
    void SetUp() override {
        Test::SetUp();
    }

    void TearDown() override {
        Test::TearDown();
    }
};

TEST_F(test,SAMPLE1) {
    EXPECT_EQ(true,true);
}