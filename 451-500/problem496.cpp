//
// Created by brayden on 2020-10-27.
//

#include "problem496.h"

#include <unordered_map>
#include <stack>
using std::vector;
using std::unordered_map;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> dict;
    for (int i = 0; i < nums2.size(); i++) {
        for (int j = i + 1; j < nums2.size(); j++) {
            if (nums2[j] > nums2[i]) {
                dict[nums2[i]] = nums2[j];
                break;
            }
        }
    }
    vector<int> res;
    for (int i : nums1) {
        if (dict.find(i) != dict.end())
            res.push_back(dict[i]);
        else
            res.push_back(-1);
    }
    return res;
}

// much simpler
vector<int> nextGreaterElement2(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> dict;
    std::stack<int> stk;
    for (int i : nums2) {
        while (!stk.empty() && stk.top() < i) {
            dict[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    for (int &i : nums1) {
        if (dict.find(i) == dict.end()) i = -1;
        else i = dict[i];
    }
    return nums1;
}