/**
 * @author AntiO2
 * @date 2024/09/20
 * @see https://leetcode.cn/problems/count-special-integers
 */

#include <string>
#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
private:
    using status_t = int;
    using res_mem_t = std::vector<std::vector<int> >; // 第一维表示数位， 第二维为status，值为搜索记录。
    std::string n_;
    std::unique_ptr<res_mem_t> pmem_;
    int dfs(int i, int len, status_t status, bool is_num, bool is_limited) {
        if(i == len) {
            // INFO("i = {}, status = {}", i, status);
            return is_num;
        }

        if(!is_limited && is_num && (*pmem_)[i][status]!=-1) {
            // INFO("i = {}, status = {}, res = {}", i, status, (*pmem_)[i][status]);
            return (*pmem_)[i][status];
        }

        auto res = 0;
        if(!is_num) {
            // 不填
            res = dfs(i + 1, len, status, is_num, false);
        }

        auto max = (int)n_[i] - '0';
        for(auto num = is_num ? 0 : 1; num < 10; ++num) {
            if(status & (1 << num)) {
                continue;
            }
            
            if(is_limited && (num > max)) {
                break;
            }
            auto add = dfs(i + 1, len, status | (1 << num), true, is_limited && (num ==max) );
            res += add;
            // INFO("i:{} num:{} max:{} add:{} res:{} is_num:{} is_limited:{}", i, num, max, add, res, is_num, is_limited);
        }
        if(!is_limited) {
            (*pmem_)[i][status] = res;
        }
        return res;
    }
public:
    int countSpecialNumbers(int n) {
        n_ = std::to_string(n);
        auto m = n_.length();
        pmem_ = std::make_unique<res_mem_t> (m, std::vector<int>(1 << 10, -1));
        return dfs(0, m, 0, false, true);
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, DISABLED_2376_test1) {
    Solution sol;
    EXPECT_EQ(sol.countSpecialNumbers(20), 19);
    // sol.test();
}

TEST_F(LeetCodeTest, 2376_test2) {
    Solution sol;
    EXPECT_EQ(sol.countSpecialNumbers(135), 110);
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