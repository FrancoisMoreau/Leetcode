//
// Created by brayden on 2020-06-14.
//

#include <string>
#include "problem443.h"

using std::vector;

// My solution, 90%, 5%
int compress(vector<char>& chars) {
    int compressed = 0, count = 1;
    char prev = chars[0];
    chars.push_back(chars.back() - 1);
    for (int i = 1; i < chars.size(); ++i) {
        if (chars[i] != prev) {
            if (count == 1)
                chars[compressed++] = prev;
            else {
                chars[compressed++] = prev;
                vector<char> tmp;
                while (count) {
                    char cur = '0' + count % 10;
                    tmp.push_back(cur);
                    count /= 10;
                }
                for (auto it = tmp.rbegin(); it != tmp.rend(); ++it)
                    chars[compressed++] = *it;
            }
            count = 1;
            prev = chars[i];
        } else {
            count++;
        }
    }
    chars.resize(compressed);
    return compressed;
}

// neat solution
int compress2(vector<char> &chars) {
    int i = 0;
    for (int j = 1, count = 1; j <= chars.size(); ++j, ++count) {
        if (j == chars.size() || chars[j] != chars[j - 1]) {
            chars[i++] = chars[j - 1];
            if (count >= 2) {
                for (char digit : std::to_string(count))
                    chars[i++] = digit;
            }
            count = 0;
        }
    }
    return i;
}