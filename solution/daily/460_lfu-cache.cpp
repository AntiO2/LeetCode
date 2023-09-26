//
// Created by Anti on 2023/9/25.
//
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
#include <list>
class LFUCache {
private:
    struct frame_t {
        int key;
        int value;
        int count;
    };
    int capacity_;
    int min_freq_{0};
    std::unordered_map <int,std::list< frame_t>::iterator> key_pos_; // 记录key在list中的位置
    std::unordered_map<int, std::list<frame_t>> freq_map_;

    /**
     * 从iter的下一个位置开始，找到根据count应该插入frame的位置
     * @param iter
     *
     */
    auto insert_frame(frame_t frame) -> std::list< frame_t>::iterator {
        const auto &count = frame.count;
        auto frame_list = freq_map_.find(count);
        if(frame_list==freq_map_.end()) {
            // 之前没有这个频率
            frame_list = freq_map_.emplace(count,std::list<frame_t>{}).first;
            frame_list->second.emplace_back(frame);
            return frame_list->second.begin();
        } else {
            frame_list->second.emplace_back(frame);
            return std::prev(frame_list->second.end());
        }
    }
public:
    LFUCache(int capacity):capacity_(capacity){};
    int get(int key) {
        auto iter = key_pos_.find(key);
        if(iter==key_pos_.end()) {
            return -1;
        }
        auto count = iter->second->count;
        auto value = iter->second->value;
        auto& old_list = freq_map_.find(count)->second;
        old_list.erase(iter->second);
        if(old_list.empty()&&count==min_freq_) {
            ++min_freq_;
        }
        frame_t f{.key = key,.value=value, .count = ++count};
        auto new_iter = insert_frame(f);
        key_pos_[key] = new_iter;
        return value;
    }

    void put(int key, int value) {
        auto iter = key_pos_.find(key);
        if(iter== key_pos_.end()) {
            // 如果之前没有这个键
            if(key_pos_.size() < capacity_) {
                // 还没有满。
                frame_t f{.key=key,.value=value,.count=1};
                auto new_iter = insert_frame(f);
                key_pos_[key] = new_iter;
            } else {
                auto& pop_iter = freq_map_[min_freq_];
                key_pos_.erase(pop_iter.front().key);
                pop_iter.pop_front();
                frame_t f{.key=key,.value=value,.count=1};
                auto new_iter = insert_frame(f);
                key_pos_[key] = new_iter;
            }
            min_freq_ = 1;
        } else {
            // 如果之前有这个键，更新值。
            auto count = iter->second->count;
            auto&old_list = freq_map_.find(count)->second;
            old_list.erase(iter->second);
            if(old_list.empty()&&count==min_freq_) {
                ++min_freq_;
            }
            frame_t f{.key = key,.value=value, .count = ++count};
            auto new_iter = insert_frame(f);
            key_pos_[key] = new_iter;
        }
    }
};

TEST(test460,SAMPLE1) {
    LFUCache l(2);
    l.put(1,1);
    l.put(2,2);
    EXPECT_EQ(l.get(1),1);
    l.put(3,3);
    EXPECT_EQ(l.get(2), -1);
    EXPECT_EQ(l.get(3),3);
    l.put(4,4);
    EXPECT_EQ(l.get(1), -1);
    EXPECT_EQ(l.get(3), 3);
    EXPECT_EQ(l.get(4), 4);
}

TEST(test460,SAMPLE2) {
    LFUCache l(4);
    l.put(1,1);
    l.put(2,2);
    l.put(3,3);
    l.put(2,2);
    l.put(4,4);
    l.put(3,3);
    l.put(5,5);
    l.put(3,3);
    l.put(5,5);
}