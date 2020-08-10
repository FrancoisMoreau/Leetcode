//
// Created by brayden on 2020-08-08.
//

#include "problem246.h"
#include <unordered_map>

using std::unordered_map;

using std::string;

// My solution, 50%
bool isStrobogrammatic(string &num) {
    int n = num.size();
    if ((n & 0x01 )&& num[n / 2] != '1' && num[n / 2] != '8' && num[n / 2] != '0') return false;
    for (int lo = 0, hi = num.size()  - 1; lo < hi; ++lo, --hi) {
        int tmp = (num[lo] - '0') * (num[hi] - '0');
        if (tmp == 54 || tmp == 64 || tmp == 1 || (num[lo] == '0' && num[hi] == '0'))
            continue;
        return false;
    }

    return true;
}

// simpler way
bool isStrobogrammatic(string num) {
    unordered_map<char, char> m {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    for (int i = 0; i <= num.size() / 2; ++i) {
        if (m[num[i]] != num[num.size() - i - 1]) return false;
    }
    return true;
}