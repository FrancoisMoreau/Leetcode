//
// Created by brayden on 2020-08-17.
//

#include "problem670.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

// My solution, O(nlogn) time
int maximumSwap(int num) {
    string str = std::to_string(num);
    string temp = str;
    std::sort(str.begin(), str.end(), std::greater<char>());
    int i = 0;
    for (; i < str.size(); ++i) {
        if (temp[i] != str[i])
            break;
    }
    if (i == str.size()) return std::stoi(str);
    auto pos = str.find_last_of(temp[i]);
    std::swap(str[pos], str[i]);
    return std::stoi(str);
}

// O(n) time, bucket
int maximumSwap2(int num) {
    string str = std::to_string(num);
    vector<int> buckets(10);
    for (int i = 0; i < str.size(); ++i)
        buckets[str[i] - '0'] = i;

    for (int i = 0; i < str.size(); ++i) {
        for (int k = 9; k > str[i] - '0'; --k) {
            if (buckets[k] > i) {
                std::swap(str[buckets[k]], str[i]);
                return std::stoi(str);
            }
        }
    }
    return num;
}

// one pass from backward
int maximumSwap3(int num) {
    auto s = std::to_string(num);
    for (int i = 0;i < s.size(); ++i) {
        auto p = std::max_element(s.rbegin(), s.rend() - i);
        if (s[i] != *p) {
            std::swap(s[i], *p);
            break;
        }
    }
    return std::stoi(s);
}