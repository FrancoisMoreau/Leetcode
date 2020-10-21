//
// Created by brayden on 2020-08-28.
//

#include "problem490.h"

using std::vector;

// My solution
bool dfs(vector<vector<int>> &maze, vector<int> start, vector<int> &destination, int x, int y) {
    if (start[0] + x < 0 || start[0] + x > maze.size() - 1 || start[1] + y < 0 || start[1] + y > maze[0].size() - 1 || maze[start[0] + x][start[1] + y] == 1) {
        if (maze[start[0]][start[1]] == -1) return false;
        if (start[0] == destination[0] && start[1] == destination[1])
            return true;
        maze[start[0]][start[1]] = -1;
        if (dfs(maze, start, destination, 1, 0)) return true;
        if (dfs(maze, start, destination, -1, 0)) return true;
        if (dfs(maze, start, destination, 0, 1)) return true;
        if (dfs(maze, start, destination, 0, -1)) return true;
        return false;
    } else {
        start[0] += x;
        start[1] += y;
        return dfs(maze, start, destination, x, y);
    }
}

bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    vector<vector<int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto &i : direction) {
        if (dfs(maze, start, destination, i[0], i[1]))
            return true;
    }
    return false;
}