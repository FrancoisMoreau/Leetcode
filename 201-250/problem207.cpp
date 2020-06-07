//
// Created by brayden on 2020-06-05.
//

#include "problem207.h"
#include <queue>

using std::vector;

// DFS
bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &on_stack, int vertex) {
    visited[vertex] = true;
    on_stack[vertex] = true;
    for (int adj : graph[vertex]) {
        if (!visited[adj]) {
            if (dfs(graph, visited, on_stack, adj))
                return true;
        }
        if (on_stack[adj])
            return true;
    }
    on_stack[vertex] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto &i : prerequisites) {
        graph[i[1]].push_back(i[0]);
    }

    vector<bool> visited(numCourses, false);
    vector<bool> on_stack(numCourses, false);
    for (int i = 0; i < numCourses; ++i) {
        if (dfs(graph, visited, on_stack, i))
            return false;
    }
    return true;
}

// BFS + indegree
bool canFinish2(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> G(numCourses);
    vector<int> indegree(numCourses, 0);
    std::queue<int> bfs;
    for (auto &e : prerequisites) {
        G[e[1]].push_back(e[0]);
        indegree[e[0]]++;
    }
    int count = 0;
    for (int i = 0; i < numCourses; ++i) {
        if (!indegree[i])
        {
            bfs.push(i);
        }
    }
    while (!bfs.empty()) {
        ++count;
        for (int j : G[bfs.front()]) {
            if (--indegree[j] == 0)
                bfs.push(j);
        }
        bfs.pop();
    }
    return count == numCourses;
}
