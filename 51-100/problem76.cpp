//
// Created by brayden on 2020-02-27.
//

#include "problem76.h"

#include <vector>
using std::vector;

// I read the discussion solution
// implement the refered template here
// 老实说， 这道题我自己思考了差不多半个小时吧
// 自己肯定有思考过双指针， 以及利用counter的
// 但我做到一半放弃了， 因为我发现还是没有办法做到， O(n)
// 仔细思考了一下， 发现差距在于几个点：
// 1. 利用dict统计所有t中出现的char的个数， 这样就不用， 我自己思考时，想到的对每个t中的char进行搜索
// 2. 也就说s和t共用了一个dict，
string minWindow(string s, string t) {
    vector<int> dict(256, 0);
    for (auto i : t)
        ++dict[i];
    int counter = t.size();
    int end = 0;
    int start = 0, minStart = 0, minLen = INT_MAX;
    while (end < s.size()) {
        if (dict[s[end]] > 0) --counter;
        --dict[s[end]];
        ++end;
        while (!counter) {
            if (end - start < minLen) {
                minStart = start;
                minLen = end - start;
            }
            ++dict[s[start]];
            if (dict[s[start]] > 0) ++counter;
            ++start;
        }
    }
    if (minLen != INT_MAX)
        return s.substr(minStart, minLen);
    return "";
}
//here, some great comment
//1. use start/end 2 pointers to represent a window
//2. move end to find a valid window (here, check counter == 0)
//3. When a valid window is found, move start to find a smaller window

// update 6 months later: Aug 2, 2020
// remember to use 256 here!!!