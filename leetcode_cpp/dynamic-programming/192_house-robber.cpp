/**
 * @author AntiO2
 * @date 2024/09/25
 * @see https://leetcode.cn/problems/house-robber
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int rob(std::vector<int>& nums) {
        auto n = nums.size();
        std::vector f(n,std::array<int, 2>{});
        f[0][1] = nums[0];
        for(int i = 1; i < n; i++) {
            f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i];
        }
        return std::max(f[n-1][0], f[n-1][1]);
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 192_test1) {
    Solution sol;
    std::vector nums{2,7,9,3,1};
    EXPECT_EQ(sol.rob(nums), 12);

    std::vector nums_2{1,2,3,1};
    EXPECT_EQ(sol.rob(nums_2), 4);
}

TEST_F(LeetCodeTest, 192_test2) {
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