//
// Created by brayden on 2020-06-02.
//

#ifndef INC_351_400_PROBLEM380_H
#define INC_351_400_PROBLEM380_H

#include <unordered_map>
#include <vector>

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (dict.find(val) != dict.end()) return false;
        dict[val] = vec.size();
        vec.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (dict.find(val) == dict.end()) return false;
        dict[vec.back()] = dict[val];
        std::swap(vec.back(), vec[dict[val]]);
        vec.pop_back();
        dict.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % vec.size();
        return vec[r];
    }

private:
    std::unordered_map<int, int> dict;
    std::vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


#endif //INC_351_400_PROBLEM380_H
