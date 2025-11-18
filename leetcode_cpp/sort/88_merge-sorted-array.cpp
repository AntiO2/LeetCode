/**
 * @author AntiO2
 * @date 2025/11/18
 * @see https://leetcode.cn/problems/merge-sorted-array
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int iter1 = m - 1;
        int iter2 = n - 1;
        int iter3 = m + n - 1;
        while(iter1 >= 0 && iter2 >= 0)
        {
            if(nums1.at(iter1) > nums2.at(iter2))
            {
                nums1[iter3] = nums1.at(iter1);
                --iter1;
            } else 
            {
                nums1[iter3] = nums2.at(iter2);
                --iter2;
            }
            --iter3;
        }

        while(iter1 >= 0)
        {
            nums1[iter3--] = nums1[iter1--];
        }
        while(iter2 >= 0)
        {
            nums1[iter3--] = nums2[iter2--];
        }
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 88_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 88_test2) {
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