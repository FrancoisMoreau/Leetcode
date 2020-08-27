//
// Created by brayden on 2020-08-24.
//

#include "problem42.h"
#include <queue>
#include <utility>
#include <stack>

using std::pair;
using std::vector;
using std::priority_queue;

// My solution in 08/2020, 5%, 20%
int trap5(vector<int>& height) {
    auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second < rhs.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < height.size(); ++i) {
        pq.push({i, height[i]});
    }

    int total = 0, left = pq.top().first, right = pq.top().first;
    pq.pop();
    while (!pq.empty()) {
        int cur_h = pq.top().second, cur_x = pq.top().first;
        pq.pop();
        if (cur_x < left) {
            total += (left - cur_x - 1) * cur_h;
            left = cur_x;
        } else if (right < cur_x) {
            total += (cur_x - right - 1) * cur_h;
            right = cur_x;
        } else {
            total -= cur_h;
        }
    }
    return total;
}

// brute-force, TLE on 314/315
int trap1(vector<int>& height) {
    int n = height.size();
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int left_max = 0, right_max = 0;
        for (int j = 0; j <= i; ++j)
            left_max = std::max(left_max, height[j]);
        for (int j = i; j <n; ++j)
            right_max = std::max(right_max, height[j]);
        total += std::min(left_max, right_max) - height[i];
    }
    return total;
}

// dynamic programming
int trap6(vector<int> &height) {
    int n = height.size();
    vector<int> left_max(n), right_max(n);
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];
    for (int i = 1; i < n; ++i)
        left_max[i] = std::max(height[i], left_max[i - 1]);
    for (int i = n - 2; i >= 0; --i)
        right_max[i] = std::max(height[i], right_max[i + 1]);

    int total = 0;
    for (int i = 1; i < n - 1; ++i)
        total += std::min(left_max[i], right_max[i]) - height[i];

    return total;
}

// using stacks, 99%, 36%
int trap2(vector<int> &height) {
    std::stack<int> stk;
    int cur = 0, res = 0;
    while (cur < height.size()) {
        while (!stk.empty() && height[cur] > height[stk.top()]) {
            int top = stk.top();
            stk.pop();
            if (stk.empty()) break;
            int dis = cur - stk.top() - 1;
            int bounded_height = std::min(height[cur], height[stk.top()]) - height[top];
            res += dis * bounded_height;
        }
        stk.push(cur++);
    }
    return res;
}

// 2 pointers, 67%, 64%
int trap(vector<int> &height) {
    int n =height.size();
    int lhs = 0, rhs = n - 1;
    int lhs_max = height[0], rhs_max = height[n - 1];
    int res = 0;
    while (lhs < rhs) {
        if (height[lhs] < height[rhs]) {
            height[lhs] < lhs_max ? res += lhs_max - height[lhs] : lhs_max = height[lhs];
            ++lhs;
        } else {
            height[rhs] < rhs_max ? res += rhs_max - height[rhs] : rhs_max = height[rhs];
            --rhs;
        }
    }
    return res;
}