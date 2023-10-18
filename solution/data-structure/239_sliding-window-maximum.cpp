//
// Created by Anti on 2023/10/18.
//
#include "fmt/core.h"
#include "logger.h"
#include "queue"
#include "gtest/gtest.h"
class Solution {
private:
    std::deque<std::pair<int, int>> dq_;
    auto update_max_window(int timestamp, const int num, const int k) -> void {
        auto prev_time = timestamp - k;// 已过期的时间
        while (!dq_.empty()) {
            if (dq_.front().first <= prev_time) {
                dq_.pop_front();
            } else {
                break;
            }
        }
        while (!dq_.empty()) {
            if (dq_.back().second <= num) {
                dq_.pop_back();
            } else {
                break;
            }
        }
        dq_.emplace_back(timestamp, num);
    }

public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {

        auto l = nums.size();
        std::vector<int> ans;
        ans.reserve(l);
        for (int i = 0; i < k - 1; ++i) {
            // 初始化
            update_max_window(i, nums[i], k);
        }
        for (int i = k - 1; i < l; ++i) {
            update_max_window(i, nums[i], k);
            ans.emplace_back(dq_.front().second);
        }
        return ans;
    }
};

TEST(test239, SAMPLE1) {
    Solution s;
    std::vector nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector ans{3, 3, 5, 5, 6, 7};
    EXPECT_EQ(s.maxSlidingWindow(nums, k), ans);
    // LOG_INFO("SAMPLE1 PASS");
}

TEST(test239, SAMPLE2) {
    Solution s;
    // LOG_INFO("SAMPLE2 PASS");
}