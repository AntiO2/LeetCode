/**
 * @author AntiO2
 * @date 2024/09/14
 * @see https://leetcode.cn/problems/removing-stars-from-a-string
 */

#include <stack>
#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    std::string removeStars(std::string s) {
        std::deque<char> stk;
        std::ostringstream oss;
        for (auto c : s) {
            if (c == '*' && !stk.empty()) {
                stk.pop_back();
            } else {
                stk.emplace_back(c);
            }
        }
        while (!stk.empty()) {
            oss << stk.front();
            stk.pop_front();
        }
        return oss.str();
    }
};

class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2390_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 2390_test2) {
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