//
// Created by brayden on 2020-02-20.
//

#include "problem275.h"

int hIndexII(vector<int>& citations) {
    int n = citations.size();
    for (int i = 0; i < n; ++i) {
        if (citations[i] >= n - i)
            return n - i;
    }
    return 0;
}

int hIndexII_2(vector<int>& citations) {
    int n = citations.size();
    int low = 0, high = citations.size() - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (citations[mid] >= n - mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return n - low;
}

