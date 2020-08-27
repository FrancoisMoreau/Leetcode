//
// Created by brayden on 2020-08-24.
//

#include "problem339.h"

using std::vector;

int subdepth(const vector<NestedInteger>& nestedList, int weight) {
    int cur_sum = 0;
    for (auto &elem : nestedList) {
        if (elem.isInteger())
            cur_sum += elem.getInteger() * weight;
        else
            cur_sum += subdepth(elem.getList(), weight + 1);
    }
    return cur_sum;
}

int depthSum(const vector<NestedInteger>& nestedList) {
    return subdepth(nestedList, 1);
    // Write your code here
}