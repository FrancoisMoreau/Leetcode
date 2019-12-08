#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::string;



vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::map<string, size_t> idx_map;
    vector<vector<string>> res;
    int idx = 0;
    for (int i = 0; i < strs.size(); ++i) {
        string tmp = strs[i];
        std::sort(tmp.begin(), tmp.end());
        if (idx_map.find(tmp) == idx_map.end()) {
            res.push_back({strs[i]});
            idx_map.insert({tmp, idx});
            ++idx;
        } else {
            res[idx_map[tmp]].push_back(strs[i]);
        }
    }
    return res;
}

vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    unordered_map<string, vector<string> > group;
    for (const auto &s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        group[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto &i : group)
        result.push_back(i.second);
    return result;
}


int main() {
    vector<string> in{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams2(in);

    for (auto &i : ans) {
        for (auto &j : i) {
            printf("%s, ", j.c_str());
        }
        printf("\n");
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}