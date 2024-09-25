/**
 * @author AntiO2
 * @date 2024/09/21
 * @see https://leetcode.cn/problems/combination-sum-iv
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector ans(target + 1,0);
        std::sort(nums.begin(), nums.end());
        ans[0] = 1;
        for(int i = 0; i <= target; ++i) {
            for(auto num:nums) {
                if(num > i) {
                    break;
                }
                ans[i] += ans[i - num];
            }
        }
        return ans[target];
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 377_test1) {
    Solution sol;
    std::vector nums{1,2,3};
    EXPECT_EQ(sol.combinationSum4(nums, 4), 7);
    // sol.test();
}

TEST_F(LeetCodeTest, 377_test2) {
    Solution sol;
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