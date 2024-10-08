/**
 * @author AntiO2
 * @date 2024/10/08
 * @see https://leetcode.cn/problems/destination-city
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::set<std::string> city, srcs;
        for(auto path:paths) {
            auto& src = path[0];
            auto& dst = path[1];
            city.emplace(src);
            city.emplace(dst);
            srcs.emplace(src);
        }

        for(auto& ci:city) {
            if(!srcs.count(ci)) {
                return ci;
            }
        }
        return "";
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 1436_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 1436_test2) {
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