//
// Created by brayden on 2020-02-27.
//

#include "problem76.h"

#include <vector>
using std::vector;


string minWindow(string s, string t) {
    vector<int> dict(256, -1);
    vector<bool> contain_set(256, false);
    for (auto i : t) {
        contain_set[i] = true;
    }
    int minLen = INT_MAX, start = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (contain_set[s[i]]) {
            if (start == -1 || s[start] == s[i]) {
                start = i;
            }

        }
    }

}