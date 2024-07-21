/**
 * @author Anti
 * @date 2024/7/21
 * @see https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion
 */

#include "gtest/gtest.h"
#include "logger.h"

class Solution {
   public:
    int maximumSum(std::vector<int>& arr) {
        auto ans = arr[0];
        if (arr.size() == 1) {
            return ans;
        }
        int no_del = std::max(arr[0] + arr[1], arr[1]);
        int del = std::max(arr[0], arr[1]);
        ans = std::max(ans, std::max(no_del, del));
        // std::cout << no_del <<"\t" << del << "\t" << ans << std::endl;
        for (int i = 2; i < arr.size(); i++) {
            auto num = arr[i];
            del = std::max(no_del, del + num);
            no_del = std::max(no_del + num, num);
            ans = std::max(ans, std::max(no_del, del));
            // std::cout << no_del <<"\t" << del << "\t" << ans << std::endl;
        }
        return ans;
    }
};
TEST(test1186, SAMPLE1) {
    Solution sol;
    auto a = std::vector<int>{1, -2, 0, 3};
    EXPECT_EQ(sol.maximumSum(a), 4);
}

TEST(test1186, SAMPLE2) {
    Solution sol;
}