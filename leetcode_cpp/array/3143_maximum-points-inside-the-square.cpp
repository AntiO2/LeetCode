/**
 * @author AntiO2
 * @date 2024/08/03
 * @see https://leetcode.cn/problems/
 * maximum-points-inside-the-square
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    int maxPointsInsideSquare(std::vector<std::vector<int>>& points,
                              std::string s) {
        auto n = s.size();
        std::vector<std::pair<int, char>> p;
        for (auto i = 0; i < n; i++) {
            auto m = std::max(std::abs(points[i][0]), std::abs(points[i][1]));
            p.emplace_back(m, s[i]);
        }
        std::sort(p.begin(), p.end());
        int ans = 0, prev_l = 0;
        std::set<char> char_set;
        int i = 0;
        for (; i < n; i++) {
            auto prev = char_set.size();
            auto l = p[i].first;
            auto c = p[i].second;
            if (l != prev_l) {
                ans = i;
                prev_l = l;
            }
            char_set.emplace(c);
            if (prev == char_set.size()) {
                break;
            }
        }
        if (i == n) {
            ans = n;
        }
        return ans;
    }
};
class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 3143_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 3143_test2) {
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