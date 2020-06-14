//
// Created by brayden on 2020-06-13.
//

#include "problem210.h"

#include <queue>


using std::vector;

// DFS, use a stack to indicates whther it's acyclic
bool dfs_topo(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &on_stack, vector<int> &res, int node) {
    if (visited[node]) return true;
    visited[node] = true;
    on_stack[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            if (!dfs_topo(graph, visited, on_stack, res, next))
                return false;
        }
        if (on_stack[next])
            return false;
    }
    on_stack[node] = false;
    res.push_back(node);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto &edge : prerequisites) {
        graph[edge[1]].push_back(edge[0]);
    }
    vector<bool > visited(numCourses, false);
    vector<bool > on_stack(numCourses, false);
    vector<int> res;
    for (int node = 0; node < numCourses; ++node) {
        if (!dfs_topo(graph, visited, on_stack, res, node))
            return {};
    }
    std::reverse(res.begin(), res.end());
    return res;
}

// BFS
vector<int> findOrder2(int numCourses, vector<vector<int>> &prerequisites) {
    if (numCourses == 0) return {};
    vector<int> indegree(numCourses);
    vector<int> order(numCourses);
    int idx = 0;

    for (auto &i : prerequisites)
        ++indegree[i[0]];

    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) {
            order[idx++] = i;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int prereq = q.front();
        q.pop();
        for (int i = 0; i < prerequisites.size(); ++i) {
            if (prerequisites[i][1] == prereq) {
                indegree[prerequisites[i][0]]--;
                if (indegree[prerequisites[i][0]] == 0) {
                    order[idx++] = prerequisites[i][0];
                    q.push(prerequisites[i][0]);
                }
            }
        }
    }

    return idx == numCourses ? order : {};
}