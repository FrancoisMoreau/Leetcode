//
// Created by brayden on 2020-05-27.
//

#include "problem88.h"

using std::vector;

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (auto i = m, j = 0; j < n; ++j, ++i) {
        nums1[i] = nums2[j];
    }
    std::partial_sort(nums1.begin(), nums1.begin() + m + n, nums1.begin() + m + n);
}

//standard solution!!!
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        nums1[k--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
}