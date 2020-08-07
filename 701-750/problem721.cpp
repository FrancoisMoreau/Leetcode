//
// Created by brayden on 2020-05-28.
//

#include "problem721.h"
#include <unordered_map>
#include <unordered_set>
#include <set>

using std::set;
using std::unordered_map;
using std::vector;
using std::string;
using std::unordered_set;

// edge case: [1, 2], [3, 4], [2, 3], we should get only one set
// quick-find
// 90%， 100%
class quickunion {
public:
    quickunion(int N) : id(N) {
        for (int i = 0; i < N; ++i)
            id[i] = i;
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    vector<int> id;
};

vector<vector<string>> accountsMerge2(vector<vector<string>>& accounts) {
    int n = accounts.size();
    quickunion uf(n);
    unordered_map<string, int> email2p;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < accounts[i].size(); ++j) {
            if (email2p.find(accounts[i][j]) != email2p.end()) {
                uf.unite(email2p[accounts[i][j]], i);
            } else {
                email2p[accounts[i][j]] = i;
            }
        }
    }
    unordered_map<int, set<string>> united;
    for (int i = 0; i < n; ++i) {
        united[uf.root(i)].insert(accounts[i].begin() + 1, accounts[i].end());
    }

    vector<vector<string>> res;
    for (auto &i : united) {
        res.push_back({accounts[i.first][0]});
        res.back().insert(res.back().end(), i.second.begin(), i.second.end());
    }
    return  res;
}

// use graph
void dfs(unordered_map<string, unordered_set<string>> &graph, string email, unordered_set<string> &visited, vector<string> &cur_res) {
    cur_res.push_back(email);
    visited.insert(email);
    for (auto &i : graph[email]) {
        if (visited.find(i) == visited.end()) {
            dfs(graph, i, visited, cur_res);
        }
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, string> email2p; // email=> username
    unordered_map<string, unordered_set<string>> graph; // email node

    for (auto &account : accounts) {
        string username = account[0];
        for (int j = 1; j < account.size(); ++j) {
            email2p[account[j]] = username;
            if (j == 1) continue;
            graph[account[j]].emplace(account[j - 1]);
            graph[account[j - 1]].emplace(account[j]);
        }
    }

    unordered_set<string> visited;
    vector<vector<string>> res;
    for (auto &item : email2p) {
        vector<string> cur_res;
        if (visited.find(item.first) == visited.end()) {
            dfs(graph, item.first, visited, cur_res);
            std::sort(cur_res.begin(), cur_res.end());
            res.push_back({item.second});
            res.back().insert(res.back().end(), cur_res.begin(), cur_res.end());
        }
    }
    return res;
}

// My solution after 3 month
// 90%, 80%
void dfs3(const vector<set<int>> &graph, vector<bool> &visited, vector<int> &id, int v, int count){
    visited[v] = true;
    id[v] = count;
    for (int adj : graph[v]) {
        if (!visited[adj])
            dfs3(graph, visited, id, adj, count);
    }
}

vector<vector<string>> accountsMerge3(vector<vector<string>>& accounts) {
    int n = accounts.size();
    vector<set<int>> graph(n, set<int>());
    unordered_map<string, int> dict;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < accounts[i].size(); ++j) {
            if (dict.find(accounts[i][j]) != dict.end()) {
                int prev = dict[accounts[i][j]];
                graph[prev].insert(i);
                graph[i].insert(prev);
            } else {
                dict[accounts[i][j]] = i;
            }
        }
    }

    vector<int> id(n);
    vector<bool> visited(n);
    int count = 0;
    vector<vector<string>> res;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            res.push_back({accounts[i][0]});
            dfs3(graph, visited, id, i, count);
            count++;
        }
    }
    vector<set<string>> emails(count, set<string>());
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < accounts[i].size(); ++j) {
            emails[id[i]].insert(accounts[i][j]);
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        res[i].insert(res[i].end(), emails[i].begin(), emails[i].end());
    }
    return res;
}