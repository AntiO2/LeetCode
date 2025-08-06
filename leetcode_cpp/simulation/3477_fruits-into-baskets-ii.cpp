/**
 * @author AntiO2
 * @date 2025/08/05
 * @see https://leetcode.cn/problems/fruits-into-baskets-ii
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        int len = fruits.size();
        std::vector<bool> used(len, false);    
        int ans = len;
        for(auto fruit: fruits) {
            for(int i = 0; i < len; i++) {
                if(fruit <= baskets[i] && !used[i]) {
                    --ans;
                    used[i] = true;
                    break;
                }
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

TEST_F(LeetCodeTest, 3477_test1) {
    Solution sol;
    std::vector fruits = {4,2,5};
    std::vector baskets = {3,5,4};
    auto ans = sol.numOfUnplacedFruits(fruits, baskets);
    EXPECT_EQ(ans, 1);
}

TEST_F(LeetCodeTest, 3477_test2) {
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