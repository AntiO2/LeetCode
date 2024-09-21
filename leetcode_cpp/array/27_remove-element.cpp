/**
 * @author AntiO2
 * @date 2024/09/06
 * @see https://leetcode.cn/problems/remove-element
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }
        auto lr = nums.end() - 1;
        auto cnt = 0;
        while(*lr==val && lr != nums.begin()) {
            ++cnt;
            --lr;
        }
        if(*lr == val) {
            return 0;
        }
        for(auto it = nums.begin();it != lr; ++it) {
            if(*it == val) {
                std::swap(*it, *lr);
                while(*lr==val) {
                    ++cnt;
                    --lr;   
                }
            }
            if(lr==it) {
                break;
            }
        }
        return nums.size() - cnt;
    }
};
class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, DISABLED_27_test1) {
    Solution sol;
    // sol.test();
    auto nums = std::vector<int>{3,2,2,3};
    auto val = 3;
    EXPECT_EQ(sol.removeElement(nums, val), 2);
    EXPECT_EQ(nums[0], 2);
    EXPECT_EQ(nums[1], 2);
}

TEST_F(LeetCodeTest, 27_test2) {
    Solution sol;
    auto nums = std::vector<int>{2, 2, 3};
    auto val = 2;
    EXPECT_EQ(sol.removeElement(nums, val), 2);
}

void LeetCodeTest::SetUp() {
    // 检查 logger 是否已经存在，避免重复创建
    err_logger = spdlog::get("stderr");
    if (!err_logger) {
        // 创建并配置 stderr 颜色日志记录器
        err_logger = spdlog::stderr_color_mt("stderr");
        err_logger->set_pattern(
            "%^[%l]\t[%T.%e]%$\t[%s:%!:%#] %v");  // 设置日志格式
        // 设置默认日志记录器
        spdlog::set_default_logger(err_logger);
    }
}