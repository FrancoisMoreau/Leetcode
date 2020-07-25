//
// Created by brayden on 2020-07-24.
//

#include "problem125.h"

using std::string;

// 30%, 72%
bool isPalindrome(string s) {
    for (auto &i : s) {
        if (isdigit(i) || isalpha(i))
            i = '*';
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    int lhs = 0, rhs = s.size() - 1;
    while (lhs < rhs) {
        if (s[lhs++] != s[rhs--])
            return false;
    }
    return true;
}

// 30%, 56%
bool isPalindrome2(string s) {
    int start = 0, end = s.size() - 1;
    while (start < end) {
        if (!isalnum(s[start])) ++start;
        else if (!isalnum(s[end])) --end;
        else {
            if (tolower(s[start++]) != tolower(s[end--]))
                return false;
        }
    }
    return true;
}

// 90%, 50%
bool isPalindrome3(string s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        while (!isalnum(s[i]) && i < j) ++i;
        while (!isalnum(s[j]) && i < j) --j;
        if (toupper(s[i]) != toupper(s[j]))
            return false;
    }
    return true;
}
