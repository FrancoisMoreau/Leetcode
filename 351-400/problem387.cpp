//
// Created by brayden on 2020-06-22.
//

#include "problem387.h"
#include <vector>

using std::vector;
using std::string;

// My Solution
int firstUniqChar(string s) {
    vector<int> count(26, 0);
    for (char c : s)
        ++count[c - 'a'];
    for (int i = 0; i < s.size(); ++i) {
        if (count[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

// Scan once
int fisrstUniqChar2(string s) {
    vector<int> idx(26, -1);
    for (int i = 0; i < s.size(); ++i) {
        if (idx[s[i] - 'a'] == -1)
            idx[s[i] - 'a'] = i;
        else
            idx[s[i] - 'a'] = INT_MAX;
    }
    int min = INT_MAX;
    for (int i : idx) {
        if (i != -1)
            min = std::min(i, min);
    }
    return min == INT_MAX ? -1 : min;
}