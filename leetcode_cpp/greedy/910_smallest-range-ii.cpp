/**
 * @author AntiO2
 * @date 2024/10/21
 * @see https://leetcode.cn/problems/smallest-range-ii
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int smallestRangeII(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        auto n = nums.size();
        auto ans = nums[n - 1] - nums[0];
        for(int i = 0; i < n - 1; ++i) {
            auto min = std::min(nums[0] + k, nums[i + 1] - k);
            auto max = std::max(nums[i] + k, nums[n - 1] - k);

            ans = std::min(ans, max - min);
            // INFO("{}\t{}\t{}", min, max, ans);
        }
        return ans;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 910_test1) {
    Solution sol;
    std::vector nums{2,7,2};
    EXPECT_EQ(sol.smallestRangeII(nums, 1), 3);
}

TEST_F(LeetCodeTest, 910_test2) {
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