//
// Created by brayden on 2020-08-28.
//

#include "problem787.h"
#include <utility>
#include <queue>

using std::queue;
using std::vector;
using std::pair;
using std::priority_queue;


// 53%, 38%, dijkstra
int findCheapestPrice1(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) {
    typedef std::tuple<int, int, int> ti;
    vector<vector<std::pair<int, int>>> graph(n);
    for (auto &i : flights) {
        graph[i[0]].push_back({i[1], i[2]});
    }
    vector<int> dist(n, -1);
    priority_queue<ti, vector<ti>, std::greater<ti>> pq;
    pq.push({0, src, K + 1});
    while (!pq.empty()) {
        auto [cost, start, stops] = pq.top();
        pq.pop();
        if (start == dst) return cost;
        if (!stops) continue;
        for (auto adj : graph[start]) {
            auto [v, w] = adj;
            pq.push({cost + w, v, stops - 1});
        }
    }
    return -1;
}

// dfs, 36%
void dfs(const vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int src, int dst, int &res, int cur_cost, int k) {
    if (src == dst) {
        res = cur_cost;
        return;
    }
    if (k == 0) return;
    visited[src] = true;
    for (auto adj: graph[src]) {
        if (!visited[adj.first]) {
            if (cur_cost + adj.second > res) continue;
            dfs(graph, visited, adj.first, dst, res, cur_cost + adj.second, k - 1);
        }
    }
    visited[src] = false;
}

int findCheapestPrice2(int n, std::vector<std::vector<int>> &flights, int src, int dst, int K) {
    vector<vector<std::pair<int, int>>> graph(n);
    for (auto &flight : flights) {
        graph[flight[0]].emplace_back(flight[1], flight[2]);
    }
    int res = INT_MAX;
    vector<bool> visited(n, false);
    dfs(graph, visited, src, dst, res, 0, K + 1);
    return res == INT_MAX ? -1 : res;
}

// bfs, 66%, 67%
int findCheapestPrice3(int n, vector<vector<int>> &flights, int src, int dst, int K) {
    vector<vector<std::pair<int, int>>> graph(n);
    for (auto &flight : flights) {
        graph[flight[0]].emplace_back(flight[1], flight[2]);
    }
    queue<std::pair<int, int>> q;
    q.push({src, 0});
    int res = INT_MAX;
    while (!q.empty()) {
        if (K < 0) break;
        for (int i = 0; i < q.size(); ++i) {
            int cur_node = q.front().first, cur_cost = q.front().second;
            q.pop();
            for (auto adj: graph[cur_node]) {
                if (cur_cost + adj.second > res) continue;
                if (adj.first == dst) res = adj.second + cur_cost;
                q.push({adj.first, adj.second + cur_cost});
            }
        }
        K--;
    }
    return res == INT_MAX ? -1 : res;
}

// bellman-Ford, 75%, 87%
int findCheapestPrice4(int n, vector<vector<int>> &flights, int src, int dst, int K) {
    vector<int> cost(n, INT_MAX);
    cost[src] = 0;
    for (int i = 0; i <= K; ++i) {
        vector<int> tmp = cost;
        for (const auto &flight: flights) {
            if (cost[flight[0]] == INT_MAX) continue;
            tmp[flight[1]] = std::min(tmp[flight[1]], cost[flight[0]] + flight[2]);
        }
        cost = tmp;
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];

}
