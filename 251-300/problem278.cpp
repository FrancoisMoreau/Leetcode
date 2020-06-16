//
// Created by brayden on 2020-06-15.
//

#include "problem278.h"

bool isBadVersion(int i) {
    return i > 0;
}

int firstBadVersion(int n) {
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (isBadVersion(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}