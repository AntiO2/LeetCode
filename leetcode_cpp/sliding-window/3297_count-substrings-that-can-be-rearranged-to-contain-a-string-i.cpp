/**
 * @author AntiO2
 * @date 2024/09/22
 * @see https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
class Solution {
public:
    long long validSubstringCount(std::string word1, std::string word2) {
        long long l1 = word1.size();
        std::array<int, 26> cnt{};
        for(auto c:word2) {
            ++cnt[c-'a'];
        }
        std::array<int, 26> cnt_now{};
        int same = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt[i]==0) {
                same++;
            }
        }
        long long i2 = 0;
        long long ans = 0;
        for(int i = 0; i < l1; ++i) {
            while(i2 < l1) {
                auto n = word1[i2] - 'a';
                ++i2;
                ++cnt_now[n];
                if(cnt_now[n] == cnt[n]) {
                    ++same;
                }
                if(same==26) {
                    break;
                }
            }
            if(same!=26) {
                break;
            }
            ans += (l1 - i2 + 1);
            auto nc = word1[i] - 'a';
            --cnt_now[nc];
            if(cnt_now[nc] == cnt[nc]) {
                --same;
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long validSubstringCount(std::string word1, std::string word2) {
        long long l1 = word1.size();
        std::array<int, 26> cnt{};
        for(auto c:word2) {
            ++cnt[c-'a'];
        }
        std::array<int, 26> cnt_now{};
        int same = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt[i]==0) {
                same++;
            }
        }
        long long i1 = 0, i2 = 0;
        while (i2 < l1) {
            auto n = word1[i2] - 'a';
            ++i2;
            ++cnt_now[n];
            if(cnt_now[n] == cnt[n]) {
                ++same;
            }
            if(same==26) {
                break;
            }
        }
        if(same!=26) {
            return 0;
        }
        long long ans = l1 - i2 + 1;
        while(i1 < i2) {
            auto ic = word1[i1] - 'a';
            if(cnt_now[ic] > cnt[ic]) {
                --cnt_now[ic];
                ++i1;
                ans += (l1 - i2 + 1);
            } else {
                break;
            }
        }
        while(i2 < l1) {
            auto n = word1[i2] - 'a';
            ++i2;
            ++cnt_now[n];
            while(i1 < i2) {
                auto ic = word1[i1] - 'a';
                if(cnt_now[ic] > cnt[ic]) {
                    --cnt_now[ic];
                    ++i1;
                    ans += (l1 - i2 + 1);
                } else {
                    break;
                }
            }
        }

        while(i1 < i2) {
            auto ic = word1[i1] - 'a';
            if(cnt_now[ic] > cnt[ic]) {
                --cnt_now[ic];
                ++i1;
                ans += (l1 - i2 + 1);
            } else {
                break;
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

TEST_F(LeetCodeTest, 3297_test1) {
    Solution sol;
    std::string word1 = "bcca";
    // dccdce 3
    // ccdce 3
    // cdce 3
    std::string word2 = "abc";
    EXPECT_EQ(sol.validSubstringCount(word1, word2), 1);
    // sol.test();
}

TEST_F(LeetCodeTest, 3297_test2) {
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