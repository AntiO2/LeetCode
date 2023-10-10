//
// Created by Anti on 2023/9/1.
//
#include "logger.h"
#include "gtest/gtest.h"

/**
 * @description 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 */
class Solution {
private:
    std::unordered_map<int, int> father_;
    std::unordered_map<int, size_t> size_;// 所在并查集的大小
    int max_size_{};                      // 最大的并查集大小
    /**
     * 返回x的祖先。约定祖先较小。
     * @param x
     * @return
     */
    auto get_root(int x) -> int {
        if (father_[x] == x) {
            return x;
        }
        return father_[x] = get_root(father_[x]);
    }

public:
    int longestConsecutive(std::vector<int> &nums) {
        max_size_ = !nums.empty();
        for (const auto &num: nums) {
            father_[num] = num;
            size_[num] = 1;
        }
        for (const auto &num: nums) {
            auto y = num + 1;
            if (father_.count(num + 1)) {
                auto father_x = get_root(num);
                auto father_y = get_root(y);// 1 3 5 4
                if (father_x != father_y) {
                    if (father_x > father_y) {
                        std::swap(father_x, father_y);
                    }
                    father_[father_y] = father_x;
                    size_[father_x] += size_[father_y];
                    max_size_ = std::max(max_size_, int(size_[father_x]));
                }
            }
        }
        return max_size_;
    }
};

TEST(S128, SAMPLE1) {
    Solution s;
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    EXPECT_EQ(s.longestConsecutive(nums), 4);
}

TEST(S128, SAMPLE2) {
    Solution s;
    std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    EXPECT_EQ(s.longestConsecutive(nums), 9);
}

TEST(S128, TRICK1) {
    Solution s;
    std::vector<int> nums = {0};
    EXPECT_EQ(s.longestConsecutive(nums), 1);
}
TEST(S128, TRICK2) {
    Solution s;
    std::vector<int> nums = {};
    EXPECT_EQ(s.longestConsecutive(nums), 0);
}