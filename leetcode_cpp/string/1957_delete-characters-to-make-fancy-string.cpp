/**
 * @author AntiO2
 * @date 2025/07/21
 * @see https://leetcode.cn/problems/delete-characters-to-make-fancy-string
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    std::string makeFancyString(std::string s) {
        char prev = 0;
        int cnt = 0;
        std::stringstream oss;
        auto cal = [&](char c) {
            if (c != prev) {
                cnt = 1;
                prev = c;
            } else {
                ++cnt;
            }

            if (cnt <= 2) {
                oss << c;
            }
        };
        for (const char c : s) {
            cal(c);
        }
        return oss.str();
    }
};
class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 1957_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 1957_test2) {
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