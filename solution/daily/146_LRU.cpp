//
// Created by Anti on 2022/12/25.
//
#include <unordered_map>

class LRUCache {
private:
    struct node {
        node* prev;
        node* next;
        int value;
        int key;
        node():prev(nullptr),next(nullptr),value(0),key(0){}
        node(int key_,int value_):key(key_),value(value_),prev(nullptr),next(nullptr){}
    };
public:
    LRUCache(int capacity) :capacity_(capacity),size_(0){
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it= cache.find(key);
        if(it==cache.end())
        {
            return -1;
        }
        moveToHead(it->second);
        return it->second->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if(it == cache.end())
        {
            if(size_<capacity_)
            {
                size_++;
                auto n = new node(key,value);
                cache.insert(std::make_pair(key,n));
                addToHead(n);
            } else
            {
                auto toRemove = tail->prev;
                cache.erase(toRemove->key);
                remove(toRemove);
                auto n = new node(key,value);
                cache.insert(std::make_pair(key,n));
                addToHead(n);
            }
        }
        else
        {
            it->second->value = value;
            moveToHead(it->second);
        }
    }
    void moveToHead(node* n)
    {
        remove(n);
        addToHead(n);
    }
    void remove(node *n)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    void addToHead(node *n)
    {
        n->next = head ->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
    }
private:

    int capacity_;
    int size_;
    node* head,*tail;
    std::unordered_map<int,node*>cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key)
 * obj->put(key,value);
 */