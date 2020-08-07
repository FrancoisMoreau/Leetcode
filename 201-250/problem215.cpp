//
// Created by brayden on 2020-05-15.
//

#include "problem215.h"
#include <queue>
#include <set>
#include <chrono>
#include <random>

using std::priority_queue;
using std::vector;

// partial sort
// Rearranges the elements in the range [first, last), in such a way that the elements before
// middle are the smallest elements in the entire range and are sorted in ascending order
int findKthLargest6(vector<int>& nums, int k) {
    std::partial_sort(nums.begin(), nums.end(), nums.begin() + k,
            [](int lhs, int rhs) {
        return lhs > rhs;
    });
    return nums[k - 1];
}

// nth element,
// the element placed in the nth position is exactly the element that would occur in this position if the range if fully sorted
int findKthLargest7(vector<int> &nums, int k) {
    std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
    return nums[k - 1];
}



// My solution after 3 month
// partial sort
int findKthLargest(vector<int> &nums, int k) {
    std::partial_sort(nums.begin(), nums.begin() + k, nums.end(), std::greater<int>());;
    return nums[k - 1];
}


// priority queue, max-heap
int findKthLargest2(vector<int> &nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    while (--k) {
        pq.pop();
    }
    return pq.top();
}

// min-heap using multiset
int findKthLargest8(vector<int> &nums, int k) {
    std::multiset<int> mset;
    for (int num : nums) {
        mset.insert(num);
        if (mset.size() > k)
            mset.erase(mset.begin());
    }
    return *mset.begin();
}

// quick select
int partition(vector<int> &nums, int lo, int hi) {
    int i = lo, j = hi + 1;
    while (true) {
        while (nums[lo] < nums[++i])
            if (i == hi) break;

        while (nums[lo] > nums[--j])
            if (j == lo) break;

        if (i >= j) break;
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[lo], nums[j]);
    return j;
}

int findKthLargest3(vector<int> &nums, int k) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(nums.begin(), nums.end(), std::default_random_engine(seed));
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int cur = partition(nums, lo, hi);
        if (cur > k - 1)
            hi = cur - 1;
        else if (cur < k - 1)
            lo = cur + 1;
        else
            return nums[cur];
    }
    return nums[k - 1];
}

// quick sort
void sort(vector<int> &nums, int lo, int hi) {
    if (hi <= lo) return ;
    int j = partition(nums, lo, hi) ;
    sort(nums, lo, j - 1);
    sort(nums, j + 1, hi);
}

void sort(vector<int> &nums) {
    sort(nums, 0, nums.size() - 1);
}
