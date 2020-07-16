//
// Created by brayden on 2020-06-22.
//

#include "problem151.h"
#include <sstream>

using std::string;

// My solution, not in place, 80%, 20%
string reverseWords(string s) {
    std::stringstream ss(s);
    string cur;
    string res;
    while (ss >> cur) {
        res = cur + " " + res;
    }
    if (!res.empty()) res.pop_back();
    return res;
}

// in-place solution, 80%, 90%
string reverseWords2(string s) {
    std::reverse(s.begin(), s.end());
    int idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            if (idx != 0) s[idx++] = ' ';
            int j = i;
            while (j < s.size() && s[j] != ' ')
                s[idx++] = s[j++];
            std::reverse(s.begin() + idx - (j - i), s.begin() + idx);
            i = j;
        }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
}