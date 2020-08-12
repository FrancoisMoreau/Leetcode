//
// Created by brayden on 2020-05-10.
//

#include "problem1130.h"

#include <algorithm>

// time: O(n^2), space: O(n)
int mctFromLeafValues(vector<int>& arr) {
    int res = 0;
    while (arr.size() > 1) {
        auto pt = std::min_element(arr.begin(), arr.end());
        if (pt > arr.begin() && pt < arr.end() - 1)
            res += std::min(*(pt - 1), *(pt + 1)) * (*pt);
        else
            res += pt == arr.begin()? (*(pt + 1) * (*pt)) : (*(pt - 1) * (*pt));
        arr.erase(pt);
    }
    return res;
}

// using stack, time: O(n), space: O(n)

int mctFromLeafValues2(vector<int> &arr) {
    vector<int> stack{INT_MAX};
    int res = 0;
    for (auto i : arr) {
        while (stack.back() < i) {
            int mid = stack.back();
            stack.pop_back();
            res += mid * std::min(stack.back() , i);
        }
        stack.push_back(i);
    }
    for (int i = 2; i < stack.size(); ++i) {
        res += stack[i] * stack[i - 1];
    }
    return res;
}