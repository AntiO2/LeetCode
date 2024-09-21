/**
 * @author AntiO2
 * @date 2024/09/11
 * @see https://leetcode.cn/problems/count-servers-that-communicate
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        std::unordered_map<int, int> row;
        std::unordered_map<int, int> col;
        auto n = grid.size();
        auto m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j]) {
                    ++row[i];
                    ++col[j];
                }
            }
        }

        auto count = 0;
        for(int i = 0; i < n; ++i) {

            for(int j = 0; j < m; ++j) {
                if(grid[i][j] && (col[j] > 1 || row[i] > 1)) {
                    ++count;
                }
            }
        }
        return count;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 1267_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 1267_test2) {
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