//
// Created by brayden on 2020-05-30.
//

#ifndef INC_101_150_PROBLEM146_H
#define INC_101_150_PROBLEM146_H


#include <queue>
#include <vector>
#include <unordered_map>
#include <list>


// 30%
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {

    }

    int get(int key) {
        if (kval.find(key) == kval.end()) return -1;
        updateLRU(key);
        return kval[key];
    }

    void put(int key, int value) {
        if (kval.size() == capacity && kval.count(key) == 0)
            evict();
        updateLRU(key);
        kval[key] = value;
    }

    // update for the list
    void updateLRU(int key) {
        if (kval.count(key))
            lru.erase(mp[key]);
        lru.push_front(key);
        mp[key] = lru.begin();
    }

    void evict() {
        mp.erase(lru.back());
        kval.erase(lru.back());
        lru.pop_back();
    }

private:
    int capacity;
    std::list<int> lru;
    std::unordered_map<int, std::list<int>::iterator> mp; //key => iterator
    std::unordered_map<int, int> kval; // key => value

};

// 70%
class LRUCache2 {
public:
    LRUCache2(int capacity) : capacity(capacity) {
        head = new DLinkedNode();
        head->pre = nullptr;
        tail = new DLinkedNode();
        tail->post = nullptr;
        head->post = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        DLinkedNode *node = cache[key];
        this->moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        // must use find here to avoid error
        if (cache.find(key) == cache.end()) {
            DLinkedNode *newNode = new DLinkedNode();
            newNode->key = key;
            newNode->value = value;
            cache[key] = newNode;
            addNode(newNode);

            if (cache.size() > capacity) {
                DLinkedNode *cur_tail = popTail();
                cache.erase(cur_tail->key);
            }
        } else {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

private:
    class DLinkedNode {
    public:
        int key;
        int value;
        DLinkedNode *pre;
        DLinkedNode *post;
        ~DLinkedNode() {
            delete pre;
            delete post;
        }
    };

    DLinkedNode *head;
    DLinkedNode *tail;
    int capacity;
    std::unordered_map<int, DLinkedNode *> cache;

    void addNode(DLinkedNode *node) {
        node->pre = head;
        node->post = head->post;
        head->post->pre = node;
        head->post = node;
    }

    void removeNode(DLinkedNode *node) {
        DLinkedNode *pre = node->pre;
        DLinkedNode *post = node->post;
        pre->post = post;
        post->pre = pre;
    }

    void moveToHead(DLinkedNode *node) {
        this->removeNode(node);
        this->addNode(node);
    }

    DLinkedNode *popTail() {
        DLinkedNode *res = tail->pre;
        removeNode(res);
        return res;
    }
};




/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //INC_101_150_PROBLEM146_H
