//
// Created by brayden on 2020-06-22.
//

#include "problem344.h"

using std::vector;

void reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        std::swap(s[i], s[s.size() - 1 - i]);
    }
}

void reverseString2(vector<char> &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        std::swap(s[i++], s[j--]);
    }
}

