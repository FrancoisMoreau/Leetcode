//首先是自己根据3sum 的实现，　写的夹逼，看到soul说的会超时，　因为参考了３sum一些判断的技巧，　所以自己提交速度还可以，　80%
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    std::sort(nums.begin(), nums.end());

    for(auto it0 = nums.cbegin(); it0 < nums.cend() - 3; ++it0) {
        if (4 * (*it0) > target)
            return res;
        if (it0 != nums.cbegin() && *it0 == *(it0 - 1))
            continue;
        for (auto it1 = it0 + 1; it1 < nums.cend() - 2; ++it1) {
            int sum01 = *it0 + *it1;
            int tardiff = target - sum01;
            if (tardiff < sum01)
                continue;
            if (it1 != it0 + 1 && *(it1) == *(it1 -1))
                continue;
            auto it2 = it1 + 1;
            auto it3 = nums.cend() - 1;
            while (it2 < it3) {
                if (*it2 + *it3 < tardiff)
                    ++it2;
                else if (*it2 + *it3 > tardiff)
                    --it3;
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
    return res;
}

//soul上提到的另外一种方法就是， 利用了hash，　构建了一个unordered_multi_map，　两两个数组成一个和，　代码贴上来。　

vector<vector<int>> foursum_map(vector<int> &nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4) return  result;
    std::sort(nums.begin(), nums.end());

    std::unordered_multimap<int, std::pair<int, int>> cache;
    for (int i = 0; i + 1 < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            cache.insert(std::make_pair(nums[i] + nums[j], std::make_pair(i, j)));
        }
    }

    for (auto i = cache.begin(); i != cache.end(); ++i) {
        int x = target - i->first;
        auto range = cache.equal_range(x);
        for (auto j = range.first; j != range.second; ++j) {
            auto a = i->second.first;
            auto b = i->second.second;
            auto c = j->second.first;
            auto d = j->second.second;
            if (a != c && a != d && b != c && b != d) {
                vector<int> vec = {nums[a], nums[b], nums[c], nums[d]};
                std::sort(vec.begin(), vec.end());
                result.push_back(vec);
            }
        }
    }
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}

