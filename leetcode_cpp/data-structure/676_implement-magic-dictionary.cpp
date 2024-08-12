/**
 * @author AntiO2
 * @date 2024/08/12
 * @see https://leetcode.cn/problems/
 */

#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#include "algorithm"
struct Trie {
    bool is_finished;
    std::unique_ptr<Trie> child[26];
    Trie() {
        is_finished = false;
        std::fill(std::begin(child), std::end(child), nullptr);
    }
};
class MagicDictionary {
public:
    MagicDictionary() {
        _root = std::make_unique<Trie>();
    }

    void buildDict(std::vector<std::string> dictionary) {
        for(const auto& word:dictionary) {
            auto cur = &_root;
            for(char ch:word) {
                int idx = ch - 'a';
                if(!(*cur)->child[idx]) {
                    (*cur)-> child[idx] = std::make_unique<Trie>();
                }
                cur = &(*cur)->child[idx];
            }
            (*cur)->is_finished = true;
        }
    }

    bool search(std::string searchWord) {
        std::function<bool(std::unique_ptr<Trie>&, int, bool)> dfs = [&](std::unique_ptr<Trie>& node, int pos, bool modified) {
            if(pos==searchWord.size()) {
                return modified && node->is_finished;
            }
            int idx = searchWord[pos] - 'a';
            if(node->child[idx]) {
                if(dfs(node->child[idx], pos + 1, modified)) {
                    return true;
                }
            }
            if(!modified) {
                for(int i = 0; i < 26; i++) {
                    if(i==idx) {
                        continue;
                    }
                    if(node->child[i]&&dfs(node->child[i], pos+1,true)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(_root, 0, false);
    }
    
private:
    std::unique_ptr<Trie> _root;
};
class Solution {
public:
    void test() {
        SPDLOG_INFO("TEST SOL");
        SPDLOG_ERROR("Error");
    }
};

class LeetCodeTest : public ::testing::Test {
protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, _test1) {
    Solution sol;
    // sol.test();
}

TEST_F(LeetCodeTest, _test2) {
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