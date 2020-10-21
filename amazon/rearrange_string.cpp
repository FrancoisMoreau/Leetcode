//
// Created by brayden on 2020-10-15.
//

#include "rearrange_string.h"
#include <vector>



std::string rearrange_string(std::string str, int num) {
    std::vector<int> count(26, 0);
    for (char c : str) {
        count[c - 'a']++;
    }
    std::string res;
    int next = 25;
    for (int i = 25; i >= 0; i--) {
        if (count[i] == 0) continue;
        if (count[i] > num) {
            res += std::string(num, i + 'a');
            count[i] -= num;
            while (next >= i || count[next] <= 0) next--;
            if (next < 0) break;
            res += (next + 'a');
            count[next]--;
            i++;
        } else {
            res += std::string(count[i], i + 'a');
        }
    }
    return res;
}

// address :
// https://leetcode.com/discuss/interview-question/724785/rearrange-original-string-and-delete-characters-java8