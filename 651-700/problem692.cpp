//
// Created by brayden on 2020-05-15.
//

#include "problem692.h"

#include <queue>
#include <unordered_map>

using std::vector;
using std::string;
using std::priority_queue;
using std::unordered_map;

struct compare {
    bool operator()(const std::pair<string, int> &lhs, const std::pair<string, int> &rhs) {
        if (lhs.second > rhs.second)
            return true;
        else if (lhs.second < rhs.second)
            return false;
        else
            return lhs.first < rhs.first;
        //could be replaced with:
        //return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
};


//priority queue
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> dict;
    for (auto &i : words)
        ++dict[i];
    priority_queue<std::pair<string, int>, vector<std::pair<string, int>>, compare> minpq;
    for (auto &i : dict) {
        minpq.push({i.first, i.second});
        if (minpq.size() > k)
            minpq.pop();
    }
    vector<string> res(minpq.size());
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        *it = minpq.top().first;
        minpq.pop();
    }
    return res;
}

// can use bucket sort here
