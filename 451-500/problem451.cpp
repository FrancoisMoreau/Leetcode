//
// Created by brayden on 2020-10-22.
//

#include "problem451.h"
#include <unordered_map>
#include <vector>
#include <queue>

using std::string;

// My solution, O(n), bucket sort
string frequencySort(string s) {
    std::unordered_map<char, int> dict;
    for (char c : s) {
        dict[c]++;
    }
    int n = s.size();
    std::vector<std::vector<char>> vec(n + 1, std::vector<char>());
    for (auto &i : dict) {
        vec[i.second].push_back(i.first);
    }
    string res;
    for (int i = n; i >= 0; i--) {
        for (char c : vec[i]) {
            res += string(i, c);
        }
    }
    return res;
}

// priority queue
string frequencySort3(string s) {
    std::unordered_map<char, int> dict;
    for (char c : s) dict[c]++;
    auto cmp = [](const std::pair<char, int> &lhs, const std::pair<char, int> &rhs) {
        return lhs.second < rhs.second;
    };
    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(cmp)> maxpq(cmp);
    for (auto &i : dict) maxpq.push(i);
    string res;
    while (!maxpq.empty()) {
        res += string(maxpq.top().second, maxpq.top().first);
        maxpq.pop();
    }
    return res;
}





// STL sort
string frequencySort2(string s) {
    std::vector<int> counts(256, 0);
    for (char c : s)
        counts[c]++;
    std::sort(s.begin(), s.end(), [&counts](char lhs, char rhs) {
        return counts[lhs] > counts[rhs];
    });
    return s;
}
