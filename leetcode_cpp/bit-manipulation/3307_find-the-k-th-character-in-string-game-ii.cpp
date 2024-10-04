/**
 * @author AntiO2
 * @date 2024/10/05
 * @see https://leetcode.cn/problems/
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    char kthCharacter(long long k, std::vector<int>& operations) {
        if(operations.empty()) {
            return 'a';
        }
        auto op = operations.back();
        operations.pop_back();
        auto n = operations.size();

        // n = 3 ( 4 - 1 )
        // a a 1 2 ^ 1
        // a a a a 2

        if(n >= 63 || k <= (1LL << n)) {
            return kthCharacter(k, operations);
        }

        char ans = kthCharacter(k - (1LL <<n), operations);
        return 'a' + (ans - 'a' + op) % 26;
    }
};
class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 3307_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 3307_test2) {
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