/**
 * @author AntiO2
 * @date 2024/08/04
 * @see https://leetcode.cn/problems/subtree-of-another-tree
 */

#include "anti_binary_tree.h"
#include "gtest/gtest.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#define INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return isSubtree(root, subRoot);
        }
        if (_isSubtree(root, subRoot)) {
            return true;
        }
        return _isSubtree(root->left, subRoot) ||
               _isSubtree(root->right, subRoot);
    }

   private:
    bool _isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return _isSubtree(root->left, subRoot->left) &&
               _isSubtree(root->right, subRoot->right);
    }
};

class LeetCodeTest : public ::testing::Test {
   protected:
    void SetUp() override;
    std::shared_ptr<spdlog::logger> err_logger;
};

TEST_F(LeetCodeTest, 572_test1) {
    Solution sol;
    auto t1 = std::make_shared<Tree>(std::vector<int>{3, 4, 5, 1, 2});
    auto t2 = std::make_shared<Tree>(std::vector<int>{4, 1, 2});
    EXPECT_EQ(sol.isSubtree(t1->root(), t2->root()), true);
}

TEST_F(LeetCodeTest, 572_test2) {
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