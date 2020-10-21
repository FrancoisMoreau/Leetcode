//
// Created by brayden on 2020-10-15.
//

#include "slowest_key.h"


char slowestkey(std::vector<std::vector<int>> keytimes) {
    int maxT = keytimes[0][1];
    char res = keytimes[0][0] + 'a';
    for (int i = 0; i < keytimes.size() - 1; i++) {
        int curT = keytimes[i + 1][1] - keytimes[i][1];
        if (curT > maxT) {
            res = keytimes[i + 1][0] + 'a';
            maxT = curT;
        }
    }
    return res;
}