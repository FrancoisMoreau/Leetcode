//
// Created by brayden on 2020-07-28.
//

#include "problem269.h"

#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>

using std::queue;
using std::string;
using std::map;
using std::set;
using std::vector;
using std::unordered_map;
using std::unordered_set;

// 77%, dfs
bool topological_sort(const vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &on_stack, vector<int> &res, int v) {
    if (visited[v]) return true;
    visited[v] = true;
    on_stack[v] = true;
    for (int adj : graph[v]) {
        if (!visited[adj]) {
            if (!topological_sort(graph, visited, on_stack, res, adj))
                return false;
        }
        if (on_stack[adj])
            return false;
    }
    on_stack[v] = false;
    res.push_back(v);
    return true;
}

string alienOrder2(vector<string> &words) {
    vector<vector<int>> graph(26, vector<int>());
    std::unordered_set<int> myset;
    for (auto &i : words) {
        for (char c : i)
            myset.insert(c - 'a');
    }
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = 0; j < std::min(words[i].size(), words[i + 1].size()); ++j) {
            if (words[i][j] != words[i + 1][j]) {
                graph[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
                break;
            }
            if (j == words[i + 1].size() - 1 && words[i + 1].size() < words[i].size())
                return "";
        }
    }
    vector<bool> visited(26, false), on_stack(26, false);
    vector<int> res;
    for (int i = 25; i >= 0; --i) {
        if (!topological_sort(graph, visited, on_stack, res, i))
            return "";
    }
    string ans;
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        if (myset.find(*it) != myset.end()) {
            ans += char(*it + 'a');
        }
    }
    return ans;
}

// bfs + indegree, 75%
bool buildGraph(vector<string> &words, map<char, set<char>> &graph, vector<int> &indegree) {
    for (auto &str : words) {
        for (char c : str)
            graph[c] = set<char>();
    }
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = 0; j < std::min(words[i].size(), words[i + 1].size()); ++j) {
            if (words[i][j] != words[i + 1][j]) {
                if (graph[words[i][j]].find(words[i + 1][j]) == graph[words[i][j]].end()) {
                    graph[words[i][j]].insert(words[i + 1][j]);
                    ++indegree[words[i + 1][j] - 'a'];
                }
                break;
            }
            if (j == words[i + 1].size() - 1 && words[i + 1].size() < words[i].size())
                return false;
        }
    }
    return true;
}

string bfs_topological_sort(const map<char, set<char>> &graph, vector<int> &indegree) {
    queue<char> bfs;
    string isolated;
    for (auto &i : graph) {
        if (indegree[i.first - 'a'] == 0) {
            if (!graph.at(i.first).empty()) {
                bfs.push(i.first);
            } else {
                isolated += i.first;
            }
        }
    }
    string order;
    while (!bfs.empty()) {
        char cur = bfs.front();
        bfs.pop();
        order += cur;
        for (const char &adj : graph.at(cur)) {
            if (--indegree[adj - 'a'] == 0)
                bfs.push(adj);
        }
    }
    int lhs = 0, rhs = 0;
    string res;
    while (lhs < order.size() && rhs < isolated.size()) {
        if (order[lhs] < isolated[rhs])
            res += order[lhs++];
        else
            res += isolated[rhs++];
    }

    if (lhs < order.size())
        res += order.substr(lhs);
    if (rhs < isolated.size())
        res += isolated.substr(rhs);

    return res;
}

string alienOrder(vector<string> &words) {
    map<char, set<char>> graph;
    vector<int> indegree(26, 0);
    if (!buildGraph(words, graph, indegree))
        return "";
    string order = bfs_topological_sort(graph, indegree);


    return order.size() == graph.size() ? order : "";
}