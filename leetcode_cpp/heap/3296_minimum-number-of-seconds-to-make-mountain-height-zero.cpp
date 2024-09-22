/**
 * @author AntiO2
 * @date 2024/09/22
 * @see https://leetcode.cn/problems/minimum-number-of-seconds-to-make-mountain-height-zero
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#include <queue>
class Solution {
    private:
    struct info {
        long long base;
        long long cnt;
    };
public:
    long long minNumberOfSeconds(long long mountainHeight, std::vector<long long>& workerTimes) {
        auto cmp = [](const std::pair<long long, info>& p1, const std::pair<long long, info>& p2) {
            return p1.first > p2.first; // 根据第一个元素创建一个最小堆
        };

        std::priority_queue<std::pair<long long, info>, std::vector<std::pair<long long, info>>, decltype(cmp)> pq(cmp);
        for(auto& workerTime:workerTimes) {
            struct info i;
            i.base = workerTime;
            i.cnt = 1;
            pq.emplace(std::make_pair(workerTime, i));
        }
        long long cnt = 0;
        long long ans = 0;
        while(cnt < mountainHeight) {
            auto p = pq.top();
            ans = std::max(ans, p.first);
            pq.pop();
            p.second.cnt++;
            p.first += p.second.cnt * p.second.base;
            pq.emplace(p);
            ++cnt;
        }
        return ans;
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 3296_test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, 3296_test2) {
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