/**
 * @author AntiO2
 * @date 2024/07/30
 * @see https://leetcode.cn/problems/double-modular-exponentiation
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    std::vector<int> getGoodIndices(std::vector<std::vector<int>>& variables,
                                    int target) {
        std::vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            auto& variable = variables[i];
            if (get_mod(get_mod(variable[0], variable[1], 10), variable[2],
                        variable[3]) == target) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }

   private:
    int get_mod(int a, int b, int m) {
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return a % m;
        }

        auto tmp = get_mod(a, b / 2, m) % m;
        if (b % 2 == 0) {
            return tmp * tmp % m;
        }
        return (tmp * tmp * a) % m;
    }
};

class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2961_test1) {
    Solution sol;
    sol.test();
}

TEST_F(LeetCodeTest, 2961_test2) {
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