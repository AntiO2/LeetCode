/**
 * @author AntiO2
 * @date 2025/11/18
 * @see https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        int now_cnt = 0;
        int now;
        int iter = 0;
        for(auto num:nums)
        {
            if(now_cnt == 0 || now != num)
            {
                now = num;
                now_cnt = 0; 
            }
            now_cnt++;
            if(now_cnt <= 2)
            {
                nums[iter++] = num;
            }
        }
        return iter;
    }
};
class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 80_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 80_test2) {
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