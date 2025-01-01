/**
 * @author AntiO2
 * @date 2025/01/01
 * @see https://leetcode.cn/problems/convert-date-to-binary
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
    private:
     std::string ito_bin_str(int i) { std::ostringstream oss;
        while (i)
        {
            oss << i % 2;
            i /= 2;
            /* code */
        }
        auto ans = oss.str();
        ;
        std::reverse(ans.begin(), ans.end());
        return ans;
     }

    public:
     std::string convertDateToBinary(std::string date) {
         int y, m, d;
         y = std::atoi(date.substr(0, 4).c_str());
         m = std::atoi(date.substr(5, 2).c_str());
         d = std::atoi(date.substr(8, 2).c_str());
         std::ostringstream ans;
         ans << ito_bin_str(y) << "-" << ito_bin_str(m) << "-"
             << ito_bin_str(d);
         return ans.str();
     }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 3280_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 3280_test2) {
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