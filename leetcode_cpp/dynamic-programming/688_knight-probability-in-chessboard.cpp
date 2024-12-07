/**
 * @author AntiO2
 * @date 2024/12/07
 * @see https://leetcode.cn/problems/knight-probability-in-chessboard
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   private:
    static constexpr int dir[8][2] = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                                      {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

   public:
    double knightProbability(int n, int k, int row, int column) {
        std::vector<std::vector<std::vector<double>>> f(
            k + 1, std::vector<std::vector<double>>(
                       n + 4, std::vector<double>(n + 4)));
        for (int i = 2; i < n + 2; i++) {
            std::fill(f[0][i].begin() + 2, f[0][i].begin() + n + 2, 1);
        }
        for (int step = 1; step <= k; step++) {
            for (int i = 2; i < n + 2; i++) {
                for (int j = 2; j < n + 2; j++) {
                    for (auto& [dx, dy] : dir) {
                        f[step][i][j] += f[step - 1][i + dx][j + dy];
                    }
                    f[step][i][j] /= 8;
                }
            }
        }
        return f[k][row + 2][column + 2];
    }
};
class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 688_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 688_test2) {
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