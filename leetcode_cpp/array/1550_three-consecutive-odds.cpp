!/**
 * @author AntiO2
 * @date 2025/05/11
 * @see https://leetcode.cn/problems/three-consecutive-odds
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
    private:
        bool isOdd(int a) {
            return a % 2 == 1;
        }
    public:
        bool threeConsecutiveOdds(vector<int>& arr) {
            auto size = arr.size();
            for(int i = 2; i < size; i++) {
                if(isOdd(arr[i]) && isOdd(arr[i -2]) && isOdd(arr[i - 1])) {
                    return true;
                }
            }
            return false;
        }
    };

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 1550_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 1550_test2) {
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