//
// Created by brayden on 2020-10-16.
//

#include "getStrictIncreaseDecrease.h"


std::vector<int> getIncDec(int num, int lowerEnd, int upperEnd) {
    std::vector<int> res;
    if (num < 3 || upperEnd - lowerEnd <= 0) return res;
    if (num > (upperEnd - lowerEnd) * 2 + 1) return res;

    int peek = upperEnd, low = lowerEnd;
    if (num > upperEnd - lowerEnd + 2) {
        int afterPeekNum = upperEnd - lowerEnd;
        int prePeekNum = num - (upperEnd - lowerEnd + 1);

        for (int i = 0; i < afterPeekNum; i++) {
            res.push_back(low++);
        }
        res.push_back(low--);
        for (int j = 0; j < prePeekNum; j++)
            res.push_back(low--);
        std::reverse(res.begin(), res.end());
    } else {
        res.push_back(peek - 1);
        for (int i = 1; i < num; i++)
            res.push_back(peek--);
    }
    return res;
}