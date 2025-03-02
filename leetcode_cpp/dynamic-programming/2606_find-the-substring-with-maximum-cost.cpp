/**
 * @author AntiO2
 * @date 2024/12/29
 * @see https://leetcode.cn/problems/find-the-substring-with-maximum-cost/
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
private:
    std::unordered_map<char, int> _char_vals;
public:
    int maximumCostSubstring(std::string s, std::string chars, std::vector<int>& vals) {
        for(int i = 0; i < 26; ++i) {
            _char_vals['a' + i] = i + 1;
        }
        int n = chars.size();
        for(int i = 0; i < n; ++ i) {
            _char_vals[chars[i]] = vals[i];
        }
        auto l = s.size();
        int dp = 0;
        int ans = 0;
        for(int i = 0; i < l; i++) {
            dp = std::max(0, dp + _char_vals[s[i]]);
            ans = std::max(dp, ans);
        }
        return ans;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2606_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 2606_test2) {
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