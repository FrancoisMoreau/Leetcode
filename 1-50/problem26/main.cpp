
// problem 26: Remove Duplicates from Sorted Array
// #using std::unique, stl
int removeDuplicates(vector<int>& nums) {
    return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
}

// #using std::upper_bound
// one way copy
int removeDuplicates2(vector<int> &nums) {
    auto p_itr = nums.begin(), begin = nums.begin(), end = nums.end();

    while (begin != end) {
        *p_itr++ = *begin;
        begin = std::upper_bound(begin, end, *begin);
    }
    return p_itr - nums.begin();
}
