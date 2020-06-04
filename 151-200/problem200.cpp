//
// Created by brayden on 2020-06-03.
//

#include "problem200.h"
#include <unordered_set>
#include <queue>

using std::queue;
using std::vector;
using std::unordered_set;
using std::pair;

// My solution, used union find
class union_find {
public:
    union_find(vector<vector<char>> &grid) : id(grid.size() * grid[0].size(), -1) {
        int rows = grid.size(), columns = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == '1') {
                    id[i * columns + j] = i * columns + j;
                    if (i != 0 && grid[i - 1][j] == '1')
                        unite(i * columns + j, (i - 1) * columns + j);
                    if (j != 0 && grid[i][j - 1] == '1')
                        unite(i * columns + j, i * columns + j - 1);
                }
            }
        }
    }

    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

    int root(int i) {
        if (id[i] == -1) return -1;
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

private:
    vector<int> id;
};

int numIslands(vector<vector<char>>& grid) {
    union_find uf(grid);
    unordered_set<int> dict;
    for (int i = 0; i < grid.size() * grid[0].size(); ++i ) {
        if (uf.root(i) != -1) {
            dict.emplace(uf.root(i));
        }
    }
    return dict.size();
}

// dfs
void eraseIslands(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    eraseIslands(grid, i - 1, j);
    eraseIslands(grid, i + 1, j);
    eraseIslands(grid, i, j - 1);
    eraseIslands(grid, i, j + 1);
}

int numIslands2(vector<vector<char>> &grid) {
     int count = 0;
     int rows = grid.size(), columns = grid[0].size();
     for (int i = 0; i < rows; ++i) {
         for (int j = 0; j < columns; ++j) {
             if (grid[i][j] == '1') {
                 ++count;
                 eraseIslands(grid, i, j);
             }
         }
     }
     return count;
}

// bfs
// https://leetcode.com/problems/number-of-islands/discuss/56589/C%2B%2B-BFSDFS