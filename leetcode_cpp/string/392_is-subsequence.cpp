/**
 * @author AntiO2
 * @date 2025/11/21
 * @see https://leetcode.cn/problems/is-subsequence
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int pos_s = 0;
        int pos_t = 0;
        while(pos_s < s.length())
        {
            while(t[pos_t] != s[pos_s] && pos_t < t.length())
            {
                ++pos_t;
            }
            if(pos_t == t.length())
            {
                return false;
            } else
            {
                ++pos_t;
            }
            ++pos_s;

        }
        return true;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 392_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 392_test2) {
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