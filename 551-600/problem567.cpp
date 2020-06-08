//
// Created by brayden on 2020-06-07.
//

#include "problem567.h"

#include <vector>

using std::vector;
using std::string;

bool checkInclusion(string s1, string s2) {
    vector<int> cnt(26);
    for (char c : s1) ++cnt[c - 'a'];
    int first = 0, last = 0;
    while (last < s2.size()) {
        if (cnt[s2[last] - 'a']-- > 0) {
            ++last;
            if (last - first == s1.size()) return true;
        } else {
            while (cnt[s2[last] - 'a'] < 0)
                cnt[s2[first++] - 'a']++;
            ++last;
        }
    }

    return false;
}