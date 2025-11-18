/**
 * @author AntiO2
 * @date 2025/11/18
 * @see https://leetcode.cn/problems/remove-duplicates-from-sorted-array
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::set<int> exist;
        int pos = 0;
        for(auto num:nums)
        {
            auto iter = exist.find(num);
            if(iter == exist.end())
            {
                nums[pos] = num;
                ++pos;
                exist.insert(num);
            }
        }
        return pos;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 26_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 26_test2) {
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