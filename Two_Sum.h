
class two_sum {
public:
    std::vector<int> solution(std::vector<int> &nums, int target) {
        std::unordered_map<int, size_t> table;
        std::vector<int> idx;
        for (int i = 0; i < nums.size(); ++i) {
            if (table.find(target - nums[i]) != table.end()) {
                idx.push_back(table[target - nums[i]]);
                idx.push_back(i);
            } else {
                table[nums[i]] = i;
            }
        }
        return idx;
    }
};
