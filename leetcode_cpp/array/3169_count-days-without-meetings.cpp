/**
 * @author AntiO2
 * @date 2025/07/11
 * @see https://leetcode.cn/problems/count-days-without-meetings
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        std::ranges::sort(
            meetings, [](const std::vector<int>& a, const std::vector<int>& b) {
                return a.at(0) < b.at(0);
            });

        int prev_left = 1, prev_right = 0;
        for (const auto& meeting : meetings) {
            if(meeting[0] > prev_right) {
               days -= (prev_right - prev_left + 1);
               prev_left = meeting[0];
            }
            prev_right = std::max(prev_right, meeting[1]);
        }
        days -= (prev_right - prev_left + 1);
        return days;
    }
};

class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 3169_test1) {
    Solution sol;
    int days = 10;
    std::vector<std::vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};
    sol.countDays(days, meetings);
}

TEST_F(LeetCodeTest, 3169_test2) {
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