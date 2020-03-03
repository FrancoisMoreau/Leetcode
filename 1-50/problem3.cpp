//
// Created by brayden on 2020-02-26.
//

#include "problem3.h"

#include <unordered_map>
#include <vector>

using std::vector;

//hash,
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    std::unordered_map<char, int> dict;
    int max_len = 0, start = 0;
    for (int i = 0; i < n; ++i) {
        if (dict.find(s[i]) != dict.end() && dict[s[i]] >= start) start = dict[s[i]] + 1;
        max_len = std::max(max_len, i - start + 1);
        dict[s[i]] = i;
    }
    return max_len;
}

// use 256-lenght vector;
int lengthOfLongestSubstring2(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = std::max(maxLen, i - start);
    }
    return maxLen;
}

// now, use the template mentioned in problem76
int lengthOfLongestSubstring3(string s) {
    vector<int> dict(256, 0);
    int begin = 0, end = 0;
    int max_Len = 0;
    int counter = 0;
    while (end < s.size()) {
        if (dict[s[end]] > 0) ++counter;
        dict[s[end]]++;
        while (counter) {
            if (end - begin > max_Len)
                max_Len = end - begin;
            if (dict[s[begin]] > 1) counter--;
            dict[s[begin]]--;
            begin++;
        }
        ++end;
    }
    return max_Len;
}




