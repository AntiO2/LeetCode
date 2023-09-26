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
    std::unordered_map <int,std::list< frame_t>::iterator> key_pos_; // 记录key在list中的位置
    std::list< frame_t> frame_;

    /**
     * 从iter的下一个位置开始，找到根据count应该插入frame的位置
     * @param iter
     * @param count
     */
    auto insert_frame(std::list< frame_t>::iterator iter,int count, frame_t frame) -> std::list< frame_t>::iterator {
        return frame_.insert(std::upper_bound(iter,frame_.end(), frame, [frame](const frame_t & f1,const frame_t & f2) {
            return f1.count<f2.count;
        }),frame);
        while(iter!=frame_.end()) {
            if(iter->count > count) {
                if(iter==frame_.begin()) {
                    frame_.push_front(frame);
                    return frame_.begin();
                }
                return frame_.insert(iter, frame);
            }
            iter++;
        }
        // 到最后都没有找到比该frame的count更大的，插入到最后就好了。
        return frame_.emplace(frame_.end(), frame);
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
        count++;
        frame_t f{.key = key,.value=value, .count = count};
        auto new_iter = insert_frame(std::next(iter->second), count, f);
        frame_.erase(iter->second);
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
                auto new_iter = insert_frame(frame_.begin(), 1, f);
                key_pos_[key] = new_iter;
            } else {
                auto pop_iter = frame_.begin();
                key_pos_.erase(pop_iter->key);
                frame_.pop_front();
                frame_t f{.key=key,.value=value,.count=1};
                auto new_iter = insert_frame(frame_.begin(), 1, f);
                key_pos_[key] = new_iter;
            }
        } else {
            // 如果之前有这个键，更新值。
            auto count = iter->second->count + 1;
            frame_t f{.key = key,.value=value, .count = count};
            auto new_iter = insert_frame(std::next(iter->second), count, f);
            frame_.erase(iter->second);
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