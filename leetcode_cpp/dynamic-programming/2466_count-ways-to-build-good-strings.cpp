/**
 * @author AntiO2
 * @date 2024/09/21
 * @see https://leetcode.cn/problems/count-ways-to-build-good-strings
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod = 1e9+7;
        auto ans = 0;

        std::vector dp(high + 1, -1);
        dp[0] = 1;
        std::function<int(int)> dfs = [&dp, zero, one, mod, &dfs](int now) {
            if(dp[now] != -1) {
                return dp[now];
            }
            auto ans = 0;
            if(now >= zero) {
                ans += dfs(now - zero);
            }
            if(now >= one) {
                ans += dfs(now - one);
            }
            dp[now] = ans % mod;
            return dp[now];
        };

        for(auto i = low; i <= high; ++i) {
            ans = (ans + dfs(i)) % mod;
        }
        return ans;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2466_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 2466_test2) {
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