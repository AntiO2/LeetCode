/**
 * @author AntiO2
 * @date 2024/09/27
 * @see https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int takeCharacters(std::string s, int k) {
        std::array<int, 3> cnt{}, target{};
        for(auto c:s) {
            ++cnt[c-'a'];
        }
        for(int i = 0; i < 3; ++i) {
            if(cnt[i] < k) {
                return -1;
            }
            target[i] = cnt[i] - k;
        }
        int i = 0;
        std::array<int, 3> slide_window{};
        auto checker = [&target, &slide_window]() {
            for(int i = 0; i < 3; i++) {
                if(slide_window[i] > target[i]) {
                    return false;
                }
                
            }
            return true;
        };
        int l = 0, r = 0;
        while(!checker()) {
            slide_window[s[r] - 'a']++;
            ++r;
        }
        int len = r - l;
        while(r < s.length()) {
            slide_window[s[r] - 'a']++;
            ++r; 
            while(!checker()) {
                slide_window[s[l] - 'a']--;
                ++l;
            }
            len = std::max(len, r - l);
        }
        return s.length() - len;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2516_test1) {
    Solution sol;
    // sol.test();
    EXPECT_EQ(sol.takeCharacters("abc", 1), 3);
}

TEST_F(LeetCodeTest, 2516_test2) {
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