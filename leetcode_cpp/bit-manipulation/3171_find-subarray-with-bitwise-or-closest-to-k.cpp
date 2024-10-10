/**
 * @author AntiO2
 * @date 2024/10/09
 * @see https://leetcode.cn/problems/find-subarray-with-bitwise-or-closest-to-k
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)


class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) {
      int ans = INT_MAX;
      for(int i = 0; i < nums.size(); ++i) {
        auto x = nums[i];
        ans = std::min(ans, std::abs(x - k));
        for(int j = i - 1; j >=0 && (x | nums[j]) != nums[j]; --j) {
          nums[j] |= x;
          ans = std::min(ans, std::abs(nums[j] - k));
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

TEST_F(LeetCodeTest, 3171_test1) {
    Solution sol;
    std::vector nums{4, 4, 4};
    EXPECT_EQ(sol.minimumDifference(nums,5), 1);
    // sol.test();
}

TEST_F(LeetCodeTest, 3171_test2) {
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
