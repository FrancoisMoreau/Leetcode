//
// Created by brayden on 2020-10-27.
//

#include "problem84.h"

#include <stack>

using std::vector;
using std::stack;

int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    stk.push(-1);
    heights.push_back(0);
    int largest = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (stk.top() != -1 && heights[i] < heights[stk.top()]) {
            int h = heights[stk.top()];
            stk.pop();
            int w = i - stk.top() - 1;
            largest = std::max(largest, h * w);
        }
        stk.push(i);
    }
    heights.pop_back();
    return largest;
}