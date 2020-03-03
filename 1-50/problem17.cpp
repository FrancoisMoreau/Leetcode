//
// Created by brayden on 2020-02-28.
//

#include "problem17.h"

// my solution
vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return vector<string>();
    vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res{""};
    for (auto i : digits) {
        int idx = i - '0';
        int cur_size = res.size();
        res.resize(cur_size * dict[idx].size());
        for (int j = cur_size; j < res.size(); j += cur_size) {
            std::copy(res.begin(), res.begin() + cur_size, res.begin() + j);
        }
        for (int k = 0; k < dict[idx].size(); ++k) {
            for (int j = 0; j < cur_size; ++j) {
                res[k * cur_size + j] += dict[idx][k];
            }
        }
    }
    return res;
}

//#1: dfs, recursive


//#2: traversal
// use algorithms a lot

