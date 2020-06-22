//
// Created by brayden on 2020-06-22.
//

#include "problem242.h"
#include <vector>

using std::vector;
using std::string;

bool isAnagram(string s, string t) {
    vector<int> count(26);
    for (char c : s)
        ++count[c - 'a'];
    for (char c : t)
        --count[c - 'a'];
    for (int i : count) {
        if (i)
            return false;
    }
    return true;
}