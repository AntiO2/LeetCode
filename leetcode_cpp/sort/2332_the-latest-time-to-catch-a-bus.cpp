/**
 * @author AntiO2
 * @date 2024/09/18
 * @see https://leetcode.cn/problems/the-latest-time-to-catch-a-bus
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

using std::vector;
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int pos = 0;
        int space = 0;
        for (int arrive : buses) {
            space = capacity;
            while (space > 0 && pos < passengers.size() && passengers[pos] <= arrive) {
                space--;
                pos++;
            }
        }
        
        pos--;
        int lastCatchTime = space > 0 ? buses.back() : passengers[pos];
        while (pos >= 0 && passengers[pos] == lastCatchTime) {
            pos--;
            lastCatchTime--;
        }

        return lastCatchTime;
    }
};


class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2332_test1) {
    Solution sol;
    // sol.test();
    auto bus = std::vector<int>{10,20};
    auto passengers = std::vector<int>{2,17,18,19};
    auto capacity = 2;
    EXPECT_EQ(sol.latestTimeCatchTheBus(bus, passengers, capacity), 16);
}

TEST_F(LeetCodeTest, 2332_test2) {
    //输入：buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
    // 输出：20
    Solution sol;
    auto bus = std::vector<int>{20, 30, 10}; // 10 20 30 
    auto passengers = std::vector<int>{19,13,26,4,25,11,21}; // 4 11 13 19 21 25 26
    auto capacity = 2;
    EXPECT_EQ(sol.latestTimeCatchTheBus(bus, passengers, capacity), 20);
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