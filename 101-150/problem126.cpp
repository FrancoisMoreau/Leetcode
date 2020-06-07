//
// Created by brayden on 2020-06-05.
//

#include "problem126.h"
#include <queue>
#include <unordered_set>

using std::string;
using std::unordered_set;
using std::vector;
using std::queue;

// My 2 days' work, ended up with TLE
bool differ_by_one(const string &lhs, const string &rhs) {
    int cnt = 1;
    for (int i = 0; i < lhs.size() && cnt >= 0; ++i) {
        if (lhs[i] != rhs[i]) --cnt;
    }
    return cnt == 0;
}


void dfs_construct(vector<vector<int>> &graph, vector<bool> visited, vector<vector<int>> &res, vector<int> &path, int cur_pos, int target, int cur_dis, int distance) {
    if (cur_dis > distance) return;
    visited[cur_pos] = true;
    if (target == cur_pos) {
        res.push_back(path);
        return;
    }
    path.push_back(cur_pos);
    for (auto &adj : graph[cur_pos]) {
        if (!visited[adj]) {
            dfs_construct(graph, visited, res, path, adj, target, cur_dis + 1, distance);
        }
    }
    path.pop_back();
    visited[cur_dis] = false;
}

vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string>& wordList) {
    if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};
    wordList.push_back(beginWord);
    int n = wordList.size();
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (differ_by_one(wordList[i], wordList[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    int target = std::distance(wordList.begin(), std::find(wordList.begin(), wordList.end(), endWord));
    // bfs to find shortest path
    std::queue<int> q;
    vector<int> dist_to(n, INT_MAX);
    dist_to[n - 1] = 0;
    vector<bool> visited(n);
    q.push(n - 1);
    while (!q.empty()) {
        if (q.front() == target)
            break;
        for (int adj : graph[q.front()]) {
            if (!visited[adj]) {
                visited[adj] = true;
                dist_to[adj] = dist_to[q.front()] + 1;
                q.push(adj);
            }
        }
        q.pop();
    }
    int shortest = dist_to[target];

    visited = std::vector<bool>(n, false);
    vector<vector<int>> idx_res;
    vector<int> path;
    dfs_construct(graph, visited, idx_res, path, n - 1, target, 0, shortest);
    vector<vector<string>> res;
    for (auto &i : idx_res) {
        res.push_back({});
        for (auto j : i) {
            res.back().push_back(wordList[j]);
        }
        res.back().push_back(wordList[target]);
    }

    return res;
}

// shortest code so far
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    vector<vector<string>> res;
    queue<vector<string>> paths;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    paths.push({beginWord});
    int level = 1;
    int minLevel = INT_MAX;
    unordered_set<string> visited;
    while (!paths.empty()) {
        vector<string> path = paths.front();
        paths.pop();
        if (path.size() > level) {
            for (auto &w : visited)
                wordSet.erase(w);
            visited.clear();
            if (path.size() > minLevel)
                break;
            else
                level = path.size();
        }

        string last = path.back();
        for (int i = 0; i < last.size(); ++i) {
            string news = last;
            for (char c = 'a'; c <= 'z'; ++c) {
                news[i] = c;
                if (wordSet.find(news) != wordSet.end()) {
                    vector<string> newpath = path;
                    newpath.push_back(news);
                    visited.insert(news);
                    if (news == endWord) {
                        minLevel = level;
                        res.push_back(newpath);
                    } else {
                        paths.push(newpath);
                    }
                }
            }
        }
    }
    return res;
}