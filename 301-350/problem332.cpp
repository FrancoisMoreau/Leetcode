//
// Created by brayden on 2020-06-08.
//

#include "problem332.h"
#include <unordered_map>
#include <set>
#include <queue>

using std::priority_queue;
using std::string;
using std::vector;
using std::unordered_map;

// My solution: 30%, 80%
bool dfs(unordered_map<string, vector<int>> &dict, vector<vector<string>> &tickets, vector<string> &res, vector<bool> &used) {
    if (res.size() == tickets.size() + 1) return true;
    for (int i : dict[res.back()]) {
        if (!used[i]) {
            res.push_back(tickets[i][1]);
            used[i] = true;
            if (dfs(dict, tickets, res, used))
                return true;
            res.pop_back();
            used[i] = false;
        }
    }
    return false;
}

vector<string> findItinerary2(vector<vector<string>>& tickets) {
    unordered_map<string, vector<int>> dict;
    for (int i = 0; i < tickets.size(); ++i) {
        dict[tickets[i][0]].push_back(i);
    }
    for (auto &i : dict) {
        std::sort(i.second.begin(), i.second.end(), [&tickets](int lhs, int rhs) {
            return tickets[lhs][1] < tickets[rhs][1];
        });
    }
    vector<bool> used(tickets.size());
    vector<string> res{"JFK"};
    dfs(dict, tickets, res, used);
    return res;
}

// In fact, it's a Eulerian Path,
void visit(unordered_map<string, std::multiset<string>> &targets, vector<string> &route,  string airport) {
    while (targets[airport].size()) {
        string next = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        visit(targets, route, next);
    }
    route.push_back(airport);
}

vector<string> findItinerary(vector<vector<string>> &tickets) {
    unordered_map<string, std::multiset<string>> targets;
    for (auto ticket : tickets) {
        targets[ticket[0]].insert(ticket[1]);
    }
    vector<string> route;
    visit(targets, route, "JFK");
    return vector<string>(route.rbegin(), route.rend());
}