//
// Created by brayden on 2020-08-07.
//

#include "problem286.h"
#include <queue>
#include <utility>

using std::vector;
using std::queue;



// bfs, my solution, beats 30%
void wallsAndGates(vector<vector<int>> &rooms) {
    queue<std::pair<int, int>> q;
    int m = rooms.size(), n = rooms[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rooms[i][j] == 0) q.push({i, j});
        }
    }
    vector<std::pair<int, int>> offset{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (auto &cur_off : offset) {
            int i = x + cur_off.first, j = y + cur_off.second;
            if (i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] == INT_MAX) {
                rooms[i][j] = rooms[x][y] + 1;
                q.push({i, j});
            }
        }
    }
}

// dfs, beats 58%
void dfs(vector<vector<int>> &rooms, int x, int y, int val) {
    if (rooms[x][y] < val) return;
    rooms[x][y] = val;
    if (x > 0) dfs(rooms, x - 1, y, val + 1);
    if (y > 0) dfs(rooms, x, y - 1, val + 1);
    if (x < rooms.size() - 1) dfs(rooms, x + 1, y, val + 1);
    if (y < rooms[0].size() - 1) dfs(rooms, x, y + 1, val + 1);
}


void wallsAndGates2(vector<vector<int>> &rooms) {
    for (int i = 0; i < rooms.size(); ++i) {
        for (int j = 0; j < rooms[0].size(); ++j) {
            if (rooms[i][j] == 0)
                dfs(rooms, i, j, 0);
        }
    }
}