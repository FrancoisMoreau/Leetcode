//
// Created by brayden on 2020-05-29.
//

#include "problem785.h"

#include <queue>
using std::vector;
using std::queue;

// 50%, 30%
bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &redblack, int node, bool mark) {
    if (visited[node]) return redblack[node] == mark;
    visited[node] = true;
    redblack[node] = mark;
    for (int adj : graph[node]) {
        if (!dfs(graph, visited, redblack, adj, !mark))
            return false;
    }
    return true;
}

bool isBipartite2(vector<vector<int>>& graph) {
    vector<bool> visited(graph.size());
    vector<bool> redblack(graph.size());
    bool mark = false;
    for (int i = 0; i < graph.size(); ++i) {
        if (visited[i]) continue;
        if (!dfs(graph, visited, redblack, i, mark))
            return false;
    }
    return true;
}

//bfs solution
// 0: not visited yet, red: -1, blue: 1
bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        if (colors[i] != 0) continue;
        queue<int> q;
        q.push(i);
        colors[i] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int adj : graph[cur]) {
                if (colors[adj] == 0) {
                    colors[adj] = -colors[cur];
                    q.push(adj);
                } else if (colors[adj] != -colors[cur]) {
                    return  false;
                }
            }
        }
    }
    return true;
}