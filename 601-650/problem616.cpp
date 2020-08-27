//
// Created by brayden on 2020-08-21.
//

#include "problem616.h"
#include <set>
#include <utility>

using std::vector;
using std::string;
using std::set;

// too long, not practical in an interview
string addBoldTag(string &s, vector<string> &dict) {
    set<string> tagset(dict.begin(), dict.end());
    vector<std::pair<int, int>> intervals;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j <= s.size(); ++j) {
            string cur = s.substr(i, j - i);
            auto it = tagset.lower_bound(cur);
            if (it == tagset.end() || it->find(cur) == std::string::npos)
                break;
            else if (*it == cur)
                intervals.emplace_back(i, j);
        }
    }
    if (intervals.empty()) return s;
    vector<std::pair<int, int>> merged{{intervals[0].first, intervals[0].second}};
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first <= merged.back().second)
            merged.back().second = std::max(intervals[i].second, merged.back().second);
        else {
            merged.emplace_back(intervals[i].first, intervals[i].second);
        }

    }
    string res;
    int prev = 0;
    for (auto &cur_pair : merged) {
        res += s.substr(prev, cur_pair.first - prev);
        res += "<b>" + s.substr(cur_pair.first, cur_pair.second - cur_pair.first) + "</b>";
        prev = cur_pair.second;
    }
    res += s.substr(prev);
    return res;

}


//
string addBoldTag2(string &s, vector<string> &dict) {
    string res;
    int n = s.size(), end = 0;
    vector<bool> bold(n, false);
    for (int i = 0; i < n; ++i) {
        for (string &word : dict) {
            int len = word.size();
            if (i + len <= n && s.substr(i, len) == word) {
                end = std::max(end, i + len);
            }
        }
        bold[i] = end > i;
    }
    for (int i = 0; i < n; ++i) {
        if (!bold[i]) {
            res.push_back(s[i]);
            continue;
        }
        int j = i;
        while (j < n && bold[j]) ++j;
        res += "<b>" + s.substr(i, j - i) + "</b>";
        i = j - 1;
    }
    return res;

}