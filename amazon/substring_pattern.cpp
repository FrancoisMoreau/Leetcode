//
// Created by brayden on 2020-10-16.
//

#include "substring_pattern.h"


int substring_pattern(std::string planConfig, std::string displayStr) {
    int lhs = planConfig.size(), rhs = displayStr.size();
    if (displayStr.empty() || lhs % rhs != 0) return -1;

    for (int i = 0; i <= lhs - rhs ; i += rhs) {
        if (planConfig.substr(i, rhs) != displayStr)
            return -1;
    }
    for (int i = 1; i <= rhs / 2; i++) {
        if (substring_pattern(displayStr, displayStr.substr(0, i)) != -1)
            return i;
    }
    return rhs;
}