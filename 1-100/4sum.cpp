
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    std::sort(nums.begin(), nums.end());

    for(auto it0 = nums.cbegin(); it0 < nums.cend() - 4; ++it0) {
        if (*it0 > target)
            return res;
        if (it0 != nums.cbegin() && *it0 == *(it0 + 1))
            continue;
        for (auto it1 = it0 + 1; it1 < nums.cend() - 3; ++it1) {
            int sum01 = *it0 + *it1;
            int tardiff = target - sum01;
            if (tardiff < sum01)
                return res;
            if (it1 != it0 + 1 && *(it1) == *(it1 -1))
                continue;
            auto it2 = it1 + 1;
            auto it3 = nums.cend() - 1;
            while (it2 < it3) {
                if (*it2 + *it3 < tardiff)
                    ++it2;
                else if (*it2 + *it3 > tardiff)
                    ++it3;
                else {
                    res.push_back({*it0, *it1, *it2, *it3});
                    while(it2 < it3 && *it2 == *(it2 + 1))
                        ++it2;
                    while (it2 < it3 && *it3 == *(it3 - 1))
                        --it3;
                    ++it2;
                    --it3;
                }
            }
        }
    }
}
