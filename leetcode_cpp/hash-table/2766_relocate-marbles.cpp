/**
 * @author AntiO2
 * @date 2024/07/24
 * @see https://leetcode.cn/problems/relocate-marbles
 */

#include <future>
#include <thread>
#include <unordered_set>
#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    std::vector<int> relocateMarbles(std::vector<int>& nums,
                                     std::vector<int>& moveFrom,
                                     std::vector<int>& moveTo) {
        auto result = std::async(std::launch::async, [&]() {
            std::unordered_set<int> set;
            for (auto num : nums) {
                set.emplace(num);
            }
            auto n = moveFrom.size();
            for (int i = 0; i < n; i++) {
                set.erase(moveFrom[i]);
                set.emplace(moveTo[i]);
            }
            std::vector<int> ans;
            for (auto i : set) {
                ans.emplace_back(i);
            }
            std::sort(ans.begin(), ans.end());
            return ans;
        });

        return result.get();
    }
};

class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 2766_test1) {
    Solution sol;
}

TEST_F(LeetCodeTest, 2766_test2) {
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