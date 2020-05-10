//
// Created by brayden on 2020-05-08.
//

#include "problem316.h"
#include <unordered_map>
#include <vector>
#include <numeric>

using std::vector;
using std::string;
using std::unordered_map;

// greedy
string removeDuplicateLetters(string s) {
    if (s.empty()) return "";
    vector<int> cnt(26, 0);
    int pos = 0;
    for (auto i : s) cnt[i - 'a']++;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] < s[pos]) pos = i;
        if (--cnt[s[i] - 'a'] == 0) break;
    }
    string sub = s.substr(pos + 1);
    sub.erase(std::remove(sub.begin(), sub.end(), s[pos]), sub.end());
    return s[pos] + removeDuplicateLetters(sub);
}

// solution 2
string removeDuplicateLetters2(string s) {
    vector<int> cnt(26, 0);
    vector<bool> visited(26, false);
    for (auto i : s) ++cnt[i - 'a'];
    string res;
    for (int i = 0; i < s.size(); ++i) {
        --cnt[s[i] - 'a'];
        if (visited[s[i] - 'a']) continue;
        while (!res.empty() && s[i] < res.back() && cnt[res.back() - 'a']) {
            visited[res.back() - 'a'] = false;
            res.pop_back();
        }
        res += s[i];
        visited[s[i] - 'a'] = true;
    }
    return res;
}

int maximumZeroSubsequenceLength(const vector<int>& vec) {
    unordered_map<int, int> d1, d2;
    d1.emplace(0, 0); // 0 values sum to 0 at the beginning
    d2 = d1;
    for (auto& element : vec) {
        for (auto& subsum : d1) {
            int opt1 = 0;
            auto it = d1.find(subsum.first + element);
            if (it != d1.end())
                opt1 = it->second;
            d2[subsum.first + element] = std::max(opt1, d1[subsum.first] + 1);
        }
        d1 = d2;
    }
    return d1[0];
}

int subcnt(vector<int> &sum, int i) {
    for (auto &j : sum) {
        if (j + i == 0)
            return 1;
        sum.push_back(i + j);
    }
    return 0;
}

int subsetsum0(const vector<int> &vec) {
    vector<int> sum{0};
    for (auto &i : vec) {
        if (subcnt(sum, i))
            return 1;
    }
    return 0;
}