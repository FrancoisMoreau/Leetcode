//
// Created by brayden on 2020-10-27.
//

#ifndef INC_701_750_PROBLEM706_H
#define INC_701_750_PROBLEM706_H

#include <vector>

struct hashnode {
    int key;
    int val;
    hashnode *next;
    hashnode(int key, int val) : key(key), val(val), next(nullptr) {}
};

class MyHashMap {
public:
    MyHashMap() {

    }

    void put(int key, int value) {
        hashnode *prev = find(key);
        if (prev->next) {
            prev->next->val = value;
        } else {
            prev->next = new hashnode(key, value);
        }
    }

    int get(int key) {
        hashnode *prev = find(key);
        if (prev->next) {
            return prev->next->val;
        }
        return -1;
    }

    void remove(int key) {
        hashnode *prev = find(key);
        if (prev && prev->next) {
            hashnode *next = prev->next;
            prev->next = prev->next->next;
            next->next = nullptr;
            delete next;
        }
    }

public:
    std::vector<hashnode *> buckets = std::vector<hashnode *>(10000, new hashnode(-1, -1));
    int idx(int key) {
        return key % 10000;
    }

    hashnode *find(int key) {
        hashnode *cur = buckets[idx(key)], *prev = nullptr;
        while (cur && cur->key != key) {
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }
};


#endif //INC_701_750_PROBLEM706_H
