//
// Created by brayden on 2020-08-11.
//

#include "problem825.h"
#include <unordered_set>
using std::vector;

// my naive solution, poor performance
int numFriendRequests2(vector<int>& ages) {
    std::sort(ages.begin(), ages.end());
    std::unordered_set<int> myset(ages.begin(), ages.end());
    int i = 0, j = 1;
    int count = 0;
    while (j < ages.size()) {
        int low_bound = ages[j] * 0.5 + 7;
        while (ages[i] <= low_bound && i < j) ++i;
        auto it = lower_bound(ages.begin() + i, ages.begin() + j + 1, ages[j]);
        count += j -  std::distance(ages.begin(), it);
        count += j - i;
        ++j;
    }
    return count;
}

// TWO tricks need to be noticed:
// 1. the condition3 is redundent
// 2. ages are between 1 and 120

// O(n) solution, 80%, 60%
int numFriendRequests(vector<int> &ages) {
    int res = 0;
    vector<int> numInAges(121), sumInAges(121);
    for (int i : ages)
        numInAges[i]++;

    for (int i = 1; i < 121; ++i)
        sumInAges[i] = numInAges[i] + sumInAges[i - 1];

    for (int i = 15; i < 121; ++i) {
        if (numInAges[i] == 0) continue;
        int count = sumInAges[i] - sumInAges[i / 2 + 7];
        res += count * numInAges[i] - numInAges[i];
    }
    return res;
}