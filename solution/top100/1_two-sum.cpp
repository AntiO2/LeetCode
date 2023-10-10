//
// Created by Anti on 2023/8/10.
//
#include "fmt/format.h"
#include "gtest/gtest.h"
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        num_mark_.clear();
        auto len = nums.size();
        for (auto i = 0; i < len; i++) {
            auto num = nums.at(i);
            mark_num(num, i);
            auto iter = num_mark_.find(target - num);
            if (iter != num_mark_.end()) {
                if (iter->second == i) {
                    continue;
                }
                return std::vector<int>{i, iter->second};
            }
        }
        return std::vector<int>{};
    }

private:
    std::unordered_map<int, int> num_mark_;

    auto mark_num(int num, int idx) -> void {
        num_mark_.emplace(num, idx);
    }
};

TEST(TWO_SUM, SIMPLE1) {
    auto target = 9;
    std::vector<int> nums = {2, 7, 11, 15};
    Solution solution;
    auto ans = solution.twoSum(nums, target);
    ASSERT_EQ(ans.size(), 2);
    EXPECT_EQ(nums.at(ans.at(1)) + nums.at(ans.at(0)), target);
}

TEST(TWO_SUM, SIMPLE2) {
    auto target = 9;
    std::vector<int> nums = {2, 4, 5, 6, 7, 8};
    Solution solution;
    auto ans = solution.twoSum(nums, target);
    ASSERT_EQ(ans.size(), 2);
    EXPECT_EQ(nums.at(ans.at(1)) + nums.at(ans.at(0)), target);
}
TEST(TWO_SUM, SIMPLE3) {
    auto target = 6;
    std::vector<int> nums = {3, 2, 4};
    Solution solution;
    auto ans = solution.twoSum(nums, target);
    ASSERT_EQ(ans.size(), 2);
    EXPECT_EQ(nums.at(ans.at(1)) + nums.at(ans.at(0)), target);
}
TEST(TWO_SUM, SIMPLE4) {
    auto target = 6;
    std::vector<int> nums = {3, 3};
    Solution solution;
    auto ans = solution.twoSum(nums, target);
    ASSERT_EQ(ans.size(), 2);
    EXPECT_EQ(nums.at(ans.at(1)) + nums.at(ans.at(0)), target);
}