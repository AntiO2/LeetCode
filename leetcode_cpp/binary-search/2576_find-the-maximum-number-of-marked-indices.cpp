/**
 * @author AntiO2
 * @date 2024/09/12
 * @see https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int maxNumOfMarkedIndices(std::vector<int>& nums) {
        auto n = nums.size();
        int left = 0, right = n / 2;
        auto check = [&nums, n](int k) {
            for(int i = 0; i < k; ++i) {
                if(nums[i] * 2 > nums[n - k + i]) {
                    return false;
                }
            }
            return true;
        };
        auto ans = 0;
        std::sort(nums.begin(), nums.end());
        while(left <= right) {
            // 查找答案
            auto k = (left + right) / 2;
            if(check(k)) {
                ans = k;
                left = k + 1;
                continue;
            } else {
                right = k - 1;
            }
        }
        return ans * 2;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2576_test1) {
    Solution sol;
    std::vector<int> nums{3,5,2,4};
    EXPECT_EQ(sol.maxNumOfMarkedIndices(nums), 2);
}

TEST_F(LeetCodeTest, 2576_test2) {
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