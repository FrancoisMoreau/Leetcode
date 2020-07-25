//
// Created by brayden on 2020-07-24.
//

#include "problem680.h"

using std::string;

// brute force, TLE, 376 case passed
bool isvalid(const string &s) {
    int i = 0, j = s.size() - 1;
    while ( i < j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

bool validPalindrome2(std::string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (isvalid(s.substr(0, i) + s.substr(i + 1)))
            return true;
    }
    return false;
}

// 12%, 50%, O(n), O(1)
bool subvalid(const string &s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

bool validPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j])
            return subvalid(s, i + 1, j) || subvalid(s, i, j - 1);
    }
    return true;
}