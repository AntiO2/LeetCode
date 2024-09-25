/**
 * @author AntiO2
 * @date 2024/09/21
 * @see https://leetcode.cn/problems/count-number-of-texts
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)


class Solution {
private:
    const std::array<int, 10> button_cnt{0,0,3,3,3,3,3,4,3,4};
    const int mod = 1e9+7;
    std::unordered_map<int, std::vector<int> > f_;
    int calc(int now, int cnt) {
        if(now == 0) {
            return 1;
        }

        auto num_cnt = button_cnt[now];
        if(f_.count(num_cnt) == 0) {
            f_.emplace(num_cnt, std::vector((int)1e5+5,0));
            f_[num_cnt][0] = 1;
        }
        if(f_[num_cnt][cnt] != 0) {
            // INFO("Already [num {}]\t{}\t f = {}",num_cnt,cnt, f_[num_cnt][cnt]);
            return f_[num_cnt][cnt];
        }
        auto ans = 0;
        for(int i = 1; i <= std::min(num_cnt, cnt); i++) {
            // INFO("[num {}]\t{}\t i = {}",num_cnt,cnt, i);
            ans = ans + calc(now, cnt - i);
            ans %= mod;
        }
        // INFO("[num {}]\t{}\t{}",num_cnt,cnt,ans);
        f_[num_cnt][cnt] = ans;
        return ans;
    }

public:
    int countTexts(std::string pressedKeys) {
        char now = 0;
        int cnt = 0;
        long long ans = 1;
        for(auto c:pressedKeys) {
            char new_char = (c - '0');
            if(now != new_char) {
                auto sub_cnt = calc(now, cnt);
                ans = ans * sub_cnt % mod;
                now = new_char;
                cnt = 1;
            } else {
                ++cnt;
            }
        } 
        auto sub_cnt = calc(now, cnt);
        ans = ans * sub_cnt % mod;
        return ans;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2266_test1) {
    Solution sol;
    std::string num="355577777788899";
    EXPECT_EQ(sol.countTexts(num), 928);
    // sol.test();
}

TEST_F(LeetCodeTest, 2266_test2) {
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