int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int tar_sum = nums[0] + nums[1] + nums[2];
    for (auto it0 = nums.cbegin(); it0 != nums.cend() - 2; ++it0) {
        auto it1 = it0 + 1;
        auto it2 = nums.cend() - 1;
        while (it1 < it2) {
            int sum = (*it0 + *it1 + *it2);
            int diff = sum - target;
            if (diff == 0)
                return sum;
            tar_sum = abs(diff) < abs(tar_sum - target) ? sum : tar_sum;
            if (diff < 0)
                ++it1;
            else
                --it2;
        }
    }
    return tar_sum;
}
