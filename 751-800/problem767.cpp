//
// Created by brayden on 2020-05-28.
//

#include "problem767.h"

#include <vector>
#include <unordered_map>
#include <queue>

using std::pair;
using std::vector;
using std::string;
using std::unordered_map;
using std::priority_queue;

// all greedy solution
// 70%, 100%, my solution, using priority queue
string reorganizeString2(string S) {
    unordered_map<char, int> dict;
    for (char c : S)
        ++dict[c];
    auto cmp = [](const pair<char, int> &lhs, const pair<char, int> &rhs) {
        return lhs.second < rhs.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(dict.begin(), dict.end(), cmp);
    string res;
    while (!pq.empty()) {
        res += pq.top().first;
        pair<char, int> tmp = pq.top();
        pq.pop();
        if (tmp.second > 1) {
            if (pq.empty()) return "";
            res += pq.top().first;
            pair<char, int> tmp2 = pq.top();
            pq.pop();
            // need to emplace tmp first, or it won't pass "abbabbaaab" => "abababab"
            pq.emplace(tmp.first, --tmp.second);
            if (tmp2.second > 1) pq.emplace(tmp2.first, --tmp2.second);
        }
    }
    return res;
}

// amazing thought:
// The solution sort the string by occurrence, i.e. the character with most occurrence is at front. For example, aaaaabbcc.
//Next, let i = 0 at the beginning, j = (n-1)/2+1 in the middle.
//We can build the answer by appending s[i++] and s[j++] sequentially.

// 100%, 100%, O(N)
string reorganizeString(string S) {
    vector<pair<char, int>> dict;
    dict.reserve(26);
    int n = S.size();
    for (int i = 0; i < 26; ++i)
        dict.emplace_back('a' + i, 0);
    for (char c : S)
        ++dict[c - 'a'].second;
    std::sort(dict.begin(), dict.end(), [](pair<char, int> &lhs, pair<char, int> &rhs) {
        return lhs.second > rhs.second;
    });
    if (dict[0].second > (n + 1) / 2) return "";
    string sortedstr;
    for (auto &i : dict)
        sortedstr += string(i.second, i.first);
    string res;
    for (int i = 0, j = (n - 1) / 2 + 1; i <= (n - 1) / 2; ++i, ++j) {
        res += sortedstr[i];
        if (j < n) res += sortedstr[j];
    }
    return res;
}

// O(n) no sort
string reorganizeString3(string S) {
    const int n = S.length();

    vector<int> count(26);
    for (char c : S) ++count[c - 'a'];

    int maxCount = *max_element(begin(count), end(count));
    if (maxCount > (n + 1) / 2) return "";

    string ans(n, ' ');

    if (maxCount == (n + 1) / 2)
        for (char c = 'a'; c <= 'z'; ++c)
            if (count[c - 'a'] == maxCount) {
                for (int i = 0; i < n; i += 2) ans[i] = c;
                count[c - 'a'] = 0;
                break;
            }

    int i = maxCount == (n + 1) / 2;

    for (char c = 'a'; c <= 'z'; ++c)
        while (count[c - 'a']--) {
            ans[i] = c;
            i += 2;
            if (i >= n) i = 1;
        }

    return ans;
}