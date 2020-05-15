//
// Created by brayden on 2020-05-14.
//

#include "problem239.h"

#include <set>

using std::multiset;
using std::vector;
using std::queue;

vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    multiset<int> pq;
    for (int i = 0; i < k; ++i)
        pq.emplace(nums[i]);
    vector<int> res(nums.size() - k + 1, *pq.rbegin());
    for (int i = 1; i < res.size(); ++i) {
        pq.erase(pq.find(nums[i - 1]));
        pq.emplace(nums[i - 1 + k]);
        res[i] = *pq.rbegin();
    }
    return res;
}

// monotonic queue
// cannot just use a queue and clear it if run into bigger number.
// Edge case: [1, 3, 1, 2, 0, 5] => [3, 3, 2, 5], while when I clear the queue I got [3, 3, 1, 5]
/* BAD CODE!
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    queue<int> monoq;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        if (!monoq.empty() && monoq.front() < i - k + 1)
            monoq.pop();
        if (!monoq.empty() && nums[monoq.front()] < nums[i]) {
            monoq = queue<int>();
        }
        monoq.push(i);
        if (i >= k - 1) res.push_back(nums[monoq.front()]);
    }
    return res;
}
 */

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    std::deque<int> dq;
    vector<int> res;
    for (int i = 0; i  < nums.size(); ++i) {
        if (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}

//3 3. O(n) solution with 2 simple pass in the array
//Reference:
//https://leetcode.com/problems/sliding-window-maximum/discuss/65881/O(n)-solution-in-Java-with-two-simple-pass-in-the-array
//
//Implement it next time!