/**
 * @author AntiO2
 * @date 2024/09/25
 * @see https://leetcode.cn/problems/delete-and-earn
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
private:
    using p_t = struct point
    {
        int not_deleted{0};
        int deleted{0};
    };
    
public:
    int deleteAndEarn(std::vector<int>& nums) {
        std::unordered_map<int, int> cnt;
        for(auto num:nums) {
            ++cnt[num];
        }
        p_t prev;
        int ans = 0;
        for(int i = 1; i <= 1e4; i++) {
            p_t now;
            now.not_deleted = std::max(prev.not_deleted, prev.deleted);
            now.deleted = prev.not_deleted + cnt[i] * i;
            ans = std::max(ans, std::max(now.not_deleted, now.deleted));
            prev = now;
        }

        return ans;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 740_test1) {
    Solution sol;
    // sol.test();
    std::vector nums{2,2,3,3,3,4};
    EXPECT_EQ(sol.deleteAndEarn(nums), 9);
}

TEST_F(LeetCodeTest, 740_test2) {
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