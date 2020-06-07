//
// Created by brayden on 2020-06-05.
//

#include "problem540.h"

using std::vector;

int singleNonDuplicate(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] != nums[mid + 1]) {
            if ((hi - mid) & 0x01) lo = mid + 1;
            else hi = mid;
        } else {
            if ((hi - mid) & 0x01) hi = mid - 1;
            else lo = mid + 2;
        }
    }
    return nums[lo];
}

// less code
int singleNonDuplicate2(vector<int> &nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo ) / 2;
        if (mid & 0x01) --mid;
        if (nums[mid] != nums[mid + 1]) hi = mid;
        else lo = mid + 2;
    }
    return lo;
}

// also an interesting answer
int singleNonDuplicate3(vector<int> &nums) {
    int lo = 0, hi = nums.size() / 2;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[2 * mid] != nums[2 * mid + 1]) hi = mid;
        else lo = mid + 1;
    }
    return nums[2 * lo];
}