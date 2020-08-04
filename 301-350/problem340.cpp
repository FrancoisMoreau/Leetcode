//
// Created by brayden on 2020-08-03.
//

#include "problem340.h"

#include <unordered_map>

using std::unordered_map;

// My solution, 36%
int lengthOfLongestSubstringKDistinct(std::string &s, int k) {
    int max_len = 0;
    unordered_map<char, int> dict;
    int start = 0, end = 0;
    while (end < s.size()) {
        dict[s[end]]++;
        if (dict[s[end]] == 1) {
            --k;
        }
        if (k < 0) {
            max_len = std::max(max_len, end - start);
            while (--dict[s[start]])
                ++start;
            ++start;
            ++k;
        }
        ++end;
    }
    max_len = std::max(max_len, end - start);
    return max_len;
}

// a simpler one, 51%
int lengthOfLongestSubstringKDistinct2(std::string &s, int k) {
    int res = 0, left = 0;
    unordered_map<char, int> dict;
    for (int i = 0; i < s.size(); ++i) {
        ++dict[s[i]];
        while (dict.size() > k) {
            if (--dict[s[left]] == 0)
                dict.erase(s[left]);
            ++left;
        }
        res = std::max(i - left + 1, res);
    }
    return res;
}

