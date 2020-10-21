//
// Created by brayden on 2020-10-15.
//

#include "consecutive_sum.h"
#include <numeric>

int consecutiveNumbersSum(int N) {
    int count = 0;
    for (int i = 1; i < sqrt(2 * N); ++i) {
        if (i & 1) {
            if (N % i == 0) ++count;
        } else {
            if (N % i == i / 2) ++count;
        }
    }
    return count;
}