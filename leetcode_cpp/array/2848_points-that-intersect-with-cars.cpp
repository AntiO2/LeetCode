/**
 * @author AntiO2
 * @date 2024/09/15
 * @see https://leetcode.cn/problems/points-that-intersect-with-cars
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
using std::vector;
#include <set>

#include <unordered_set>
class Solution {
    
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        std::unordered_set<int> s;
        for(auto &car:nums) {
            for(auto i = car[0]; i <= car[1]; i++) {
                s.insert(i);
            }
        }
        return s.size();
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2848_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 2848_test2) {
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