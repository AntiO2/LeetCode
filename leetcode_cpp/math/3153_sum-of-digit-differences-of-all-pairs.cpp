/**
 * @author AntiO2
 * @date 2024/08/30
 * @see https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    long long sumDigitDifferences(std::vector<int>& nums) {
        long long ans = 0;
        auto n = nums.size();
        auto idx = 0;
        auto done = false;
        while(!done) {
            std::vector<int> cnt(10,0);
            for(auto& num:nums) {
                int dig = 0;
                if(!get_idx(num, idx, dig)) {
                    done = true;
                    break;
                }
                cnt[dig]++;
            }
            for(auto c:cnt) {
                ans += c * (n - c);
            }
            ++idx;
        }
        return ans / 2;
    }
private:
    auto get_idx(int num, int idx, int& dig) -> bool{
        int x = 1;
        for(int i = 0 ; i < idx; i++) {
            x *=10;
        }
        if(num < x) {
            return false;
        }   
        dig = (num / x) %10;
        return true;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 3153_test1) {
    Solution sol;
    // sol.test();
    std::vector<int> nums{10,10,10,10};
    EXPECT_EQ(sol.sumDigitDifferences(nums), 0);
}

TEST_F(LeetCodeTest, 3153_test2) {
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