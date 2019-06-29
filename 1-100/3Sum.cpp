
//自己写的有bug，　参考了别人的实现。　效率最高了吧。　具体情况看豆瓣

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3)
        return res;
    std::sort(nums.begin(), nums.end());
    for (auto it0 = nums.cbegin(); it0 < nums.cend() - 2; ++it0) {
        auto it1 = it0 + 1;
        auto it2 = nums.cend() - 1;
        while (it1 < it2) {
            if (*it1 + *it2 + *it0 < 0) {
                ++it1;
            }
            else if (*it1 + *it2 + *it0 > 0) {
                --it2;
            }
            else {
                res.push_back({*it0, *it1, *it2});
                ++it1;
                --it2;
                while (*it1 == *(it1 -1) && *(it2 + 1) == *it2 && it1 < it2)
                    ++it1;
            }
        }
        while (*it0 == *(it0 + 1) && it0 < nums.cend() -2)
            ++it0;
    }
    return res;
}

