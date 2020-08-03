//
// Created by brayden on 2020-08-02.
//

#include "problem438.h"

#include <unordered_set>

using std::unordered_set;
using std::vector;
using std::string;

// TLE
vector<int> findAnagrams2(string s, string p) {
    if (s.size() < p.size()) return {};
    std::sort(p.begin(), p.end());
    std::unordered_set<string> allsets;
    do {
        allsets.insert(p);
    } while (std::next_permutation(p.begin(), p.end()));
    int n = p.size();
    vector<int> res;
    for (int i = 0; i <= s.size() - p.size(); ++i) {
        if (allsets.find(s.substr(i, n)) != allsets.end())
            res.push_back(i);
    }
    return res;
}

// 97%, 96%, sliding window
vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) return {};
    vector<int> dict(26, 0);
    for (char c : p)
        ++dict[c - 'a'];
    int first = 0, last = 0;
    vector<int> res;
    while (first < s.size()) {
        dict[s[first] - 'a']--;
        while (dict[s[first] - 'a'] < 0) {
            dict[s[last++] - 'a']++;
        }
        ++first;
        if (first - last == p.size()) {
            res.push_back(last);
        }
    }
    return res;
}
