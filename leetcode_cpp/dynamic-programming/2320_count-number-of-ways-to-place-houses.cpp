/**
 * @author AntiO2
 * @date 2024/09/25
 * @see https://leetcode.cn/problems/count-number-of-ways-to-place-houses
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)



class Solution {
private:
    static constexpr int MOD = 1e9 + 7, MX = 1e4 + 1;
    int f[MX] = {1, 2};
    constexpr void init() {
        for (int i = 2; i < MX; ++i)
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        return;
    }
public:
    int countHousePlacements(int n) {
        init();
        return (long) f[n] * f[n] % MOD;
    }
};


class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2320_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 2320_test2) {
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