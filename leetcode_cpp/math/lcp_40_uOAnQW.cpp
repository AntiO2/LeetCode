/**
 * @author AntiO2
 * @date 2024/08/01
 * @see https://leetcode.cn/problems/uOAnQW
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    void test() {
        SPDLOG_INFO("TEST SOL");
        SPDLOG_ERROR("Error");
    }
    int maxmiumScore(std::vector<int>& cards, int cnt) {
        std::sort(cards.begin(), cards.end(), std::greater<int>());
        int s = 0;
        for (int i = 0; i < cnt; ++i) {
            s += cards[i];
        }
        if (!(s % 2)) {
            return s;
        }
        auto f = [&](int now) {
            auto iter = cards.begin() + cnt;
            while (iter != cards.end()) {
                if ((*iter) % 2 != now % 2) {
                    break;
                }
                ++iter;
            }
            return iter;
        };
        auto x = cards[cnt - 1];
        int ans = 0;
        auto it = f(x);
        if (it != cards.end()) {
            ans = s - x + *it;
        }
        for (auto i = cnt - 2; i >= 0; --i) {
            if (cards[i] % 2 != x % 2) {
                it = f(cards[i]);
                if (it != cards.end()) {
                    ans = std::max(ans, s - cards[i] + *it);
                }
            }
        }
        return ans;
    }
};

class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, lcp_40_test1) {
    Solution sol;
    std::vector<int> a{2, 2, 2, 2};
    sol.maxmiumScore(a, 3);
}

TEST_F(LeetCodeTest, lcp_40_test2) {
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