/**
 * @author AntiO2
 * @date 2024/08/05
 * @see
 * https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    int findIntegers(int n) {
        int dp[33] = {1, 1};
        for (int i = 2; i < 32; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int ans = 0;
        int pre = 0;
        for (int i = 31; i >= 0; i--) {
            auto val = 1 << i;
            if ((n & val) != 0) {
                ans += dp[i + 1];
                if (pre == 1) {  // 出现连续的1
                    break;
                }
                pre = 1;
            } else {
                pre = 0;
            }
            if (i == 0) {
                ans++;
            }
        }
        return ans;
    }
};

// 5
// 0        1
// 0 1      0 1
// 01 01    01 0

// 1 1 2 3 5 8
class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 600_test1) {
    Solution sol;
    // sol.test();
    EXPECT_EQ(sol.findIntegers(5), 5);
}

TEST_F(LeetCodeTest, 600_test2) {
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