/**
 * @author AntiO2
 * @date 2024/10/05
 * @see https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    long long countOfSubstrings(std::string word, int k) {
                auto slide = [&word](int k) {
            auto ans = 0LL;

            int l = 0, r = 0;
            int cnt_not_y = 0;
            std::unordered_map<int, int> cnt_y;

            auto check_y = [&cnt_y]() {
                return cnt_y.size() == 5;
            };

            auto is_y =  [](char c) {
                static const std::vector yuan {'a', 'e', 'i', 'o', 'u'};
                for(auto y:yuan) {
                    if(c==y) {
                        return true;
                    }
                }
                return false;
            };

            while(r < word.size()) {
                if(is_y(word[r])) {
                    ++cnt_y[word[r]];
                } else {
                    ++cnt_not_y;
                }
                ++r;
                while(check_y() && cnt_not_y >= k) {
                    auto out = word[l];
                    if(is_y(out)) {
                        if(--cnt_y[out] == 0) {
                            cnt_y.erase(out);
                        } 
                    } else {
                        --cnt_not_y;
                    }
                    ++l;
                }
                ans+=l;
            }
            return ans;
        };

        return slide(k) - slide(k + 1);
    }
};
class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 3306_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 3306_test2) {
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