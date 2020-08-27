//
// Created by brayden on 2020-08-24.
//

#include "problem839.h"
#include <unordered_set>

using std::unordered_set;
using std::vector;
using std::string;

// My first solution, connected components, 30%, 30%
void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs(graph, visited, adj);
        }
    }
}

int numSimilarGroups2(vector<string>& A) {
    int n = A.size();
    vector<vector<int>> graph(n);
    int word_len = A[0].size();
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i + 1; j < A.size(); ++j) {
            int count = 0;
            for (int k = 0; k < word_len; ++k) {
                if (A[i][k] != A[j][k]) ++count;
            }
            if (count == 2 || count == 0) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    // use connected components
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            ++count;
        }
    }
    return count;
}

// union find class
class uf {
public:
    uf(int n) : sz(n) {
        for (int i = 0; i < n; ++i)
            id.push_back(i);
    }

    int getroot(int i) {
        if (id[i] == i)
            return i;
        else {
            id[i] = id[id[i]];
            return getroot(id[i]);
        }
    }

    void connect(int i, int j) {
        int lhs = getroot(i);
        int rhs = getroot(j);
        if (lhs != rhs) {
            --sz;
            id[lhs] = id[rhs];
        }
    }

    int get_size() {
        return sz;
    }

private:
    vector<int> id;
    int sz;
};

int numSimilarGroups(vector<string>& A) {
    int n = A.size();
    uf myuf(n);
    int word_len = A[0].size();
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i + 1; j < A.size(); ++j) {
            int count = 0;
            for (int k = 0; k < word_len; ++k) {
                if (A[i][k] != A[j][k]) ++count;
            }
            if (count == 2 || count == 0) {
                myuf.connect(i, j);
            }
        }
    }

    return myuf.get_size();
}