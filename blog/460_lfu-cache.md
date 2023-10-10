# [LeetCode] 460.[LFU 缓存](https://leetcode.cn/problems/lfu-cache/)

## 题目概述

实现LFU缓存。

LFU（least frequently used (LFU) page-replacement
algorithm）。即最不经常使用页置换算法，要求在页置换时置换引用计数最小的页，因为经常使用的页应该有一个较大的引用次数。如果有相同使用次数（get和put都会增加使用次数），那么淘汰掉最远使用的那个。

## 最开始的思路

一开始用一个map存放key-frame list::
iterator,然后在一个链表中存储kv对和频次。这里频次按照从小到大，从旧到新在链表中排列，然后每次put和get维护链表顺序（因为次数发生了改变），get时从map中找到迭代器位置，获取value。每次淘汰掉list第一个。

但是问题就出现在维护中，如何找到frame在次数改变后应当存放的位置呢？这里我一开始想的因为list中的频次是从小到大排的，就可以使用upper
bound找到次数改变后的位置。但是每次的时间复杂度来到了$logn$。于是很自然的超时了。

```C++
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

```

## to be vega

考虑到list的特殊性，是根据离散的点(1,2,3,4...)
，所以可以将频率作为map的键，来快速找到一个相同的频率列表。比如当前的一个key访问了两次，然后更新后需要找到3的频率，之前是通过二分查找找到3的开始的地方，现在是通过map查找。

```c++
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
```

然后每次put和get时，替换对应的操作

```C++
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
```

