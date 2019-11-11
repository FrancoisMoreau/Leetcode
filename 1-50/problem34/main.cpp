#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> searchRange(vector<int>& nums, int target) {
    auto res = std::equal_range(nums.cbegin(), nums.cend(), target);
    if (res.first != res.second)
        return {static_cast<int>(res.first - nums.cbegin()), static_cast<int>(res.second - nums.cbegin() - 1)};
    else
        return {-1, -1};
}

int searchInsert(vector<int>& nums, int target) {
    auto res = std::equal_range(nums.begin(), nums.end(), target);
    return res.first - nums.begin();
}

using std::cout;
using std::endl;

int main() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    vector<int> res0 = searchRange(nums, 8);
    std::cout << "[" << res0[0] << ", " << res0[1] << "]\n";
    vector<int> res1 = searchRange(nums, 6);
    std::cout << "[" << res1[0] << ", " << res1[1] << "]\n";

    vector<int> nums2{1, 3, 5, 6};
    cout << "search Insert:\n";
    cout << searchInsert(nums2, 5) << endl;
    cout << searchInsert(nums2, 3) << endl;
    cout << searchInsert(nums2, 7) << endl;
    cout << searchInsert(nums2, 0) << endl;

    return 0;
}