//
// Created by brayden on 2020-02-21.
//

#include "problem243.h"
#include <algorithm>


int shortestDistance(vector<string>& words, string word1, string word2) {
    int n = words.size();
    int lhs_pos = -n, rhs_pos = -n;
    int shortes_dis = INT_MAX, cur_dis = 0;
    for (int i = 0; i < n; ++i) {
        if (words[i] == word1) {
            lhs_pos = i;
            cur_dis = lhs_pos - rhs_pos;
            shortes_dis = cur_dis < shortes_dis ? cur_dis : shortes_dis;
        }
        if (words[i] == word2) {
            rhs_pos = i;
            cur_dis = rhs_pos - lhs_pos;
            shortes_dis = cur_dis < shortes_dis ? cur_dis : shortes_dis;
        }
    }
    // could do optimization
    // shortest_dis = std::min(cur_dis, abs(lhs - pos)
    return shortes_dis;
}

// a better solution
// used only 1 variable, and less if cases
int shortestDistance2(vector<string>& words, string word1, string word2) {
    int min_dis = words.size();
    int lastIndex = -1;
    for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word1 || words[i] == word2) {
            if (lastIndex != -1 && words[i] != words[lastIndex])
                min_dis = std::min(min_dis, i - lastIndex);
            lastIndex = i;
        }
    }
    return min_dis;
}