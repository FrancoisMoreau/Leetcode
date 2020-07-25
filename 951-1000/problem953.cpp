//
// Created by brayden on 2020-07-15.
//

#include "problem953.h"

using std::vector;
using std::string;

bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() <= 1) return true;
    vector<int> pos(26);
    for (int i = 0; i < order.size(); ++i) {
        pos[order[i] - 'a'] = i;
    }
    for (int i = 0; i < words.size() - 1; ++i) {
        int cur_pos = 0, max_len = std::min(words[i].size(), words[i + 1].size());
        while (words[i][cur_pos] == words[i + 1][cur_pos] && cur_pos < max_len)
            ++cur_pos;
        if (cur_pos == max_len) {
            if (words[i].size() > words[i + 1].size())
                return false;
        } else {
            if (pos[words[i][cur_pos] - 'a'] > pos[words[i + 1][cur_pos] - 'a'])
                return  false;
        }
    }
    return true;
}

bool isAlienSorted2(vector<string> &words, string order) {
    vector<int> mapping(26);
    for (int i = 0; i < 26; ++i) {
        mapping[order[i] - 'a'] = i;
    }
    for (auto &word : words) {
        for (auto &c : word)
            c = mapping[c - 'a'];
    }
    return std::is_sorted(words.begin(), words.end());
}