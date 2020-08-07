//
// Created by brayden on 2020-05-31.
//

#include "problem133.h"

#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::unordered_set;
using std::unordered_map;

// My solution, dfs, 95%, 100%
Node *dfs_construct(Node *node, unordered_map<Node *, Node *> &mp) {
    if (mp.find(node) != mp.end()) return mp[node];
    Node *duplicate = new Node(node->val);
    mp[node] = duplicate;
    for (auto &i : node->neighbors) {
        Node *copied = dfs_construct(i, mp);
        duplicate->neighbors.push_back(copied);
    }
    return duplicate;
}

Node* cloneGraph(Node* node) {
    if (!node) return node;
    unordered_map<Node *, Node *> mp;
    return dfs_construct(node, mp);
}

// My solution after 3 month: Aug 5, 2020
void dfs(unordered_map<Node *, Node *> &dict, unordered_set<Node *> &visited,  Node *node) {
    if (visited.find(node) != visited.end()) return;
    visited.insert(node);

    for (auto &adj : node->neighbors) {
        if (dict.find(adj) == dict.end()) {
            Node *clone = new Node(adj->val);
            dict[adj] = clone;
        }
        dict[node]->neighbors.push_back(dict[adj]);
        dfs(dict, visited, adj);
    }
}

Node* cloneGraph2(Node* node) {
    if (!node) return nullptr;
    Node *clone = new Node(node->val);
    unordered_map<Node *, Node *> dict;
    unordered_set<Node *> visited;
    dict[node] = clone;
    dfs(dict, visited, node);
    return clone;
}

// bfs
// 75%, 80%
Node* cloneGraph4(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node *, Node *> dict;
    std::queue<Node *> q;
    q.push(node);
    dict[node] = new Node(node->val);
    while (!q.empty()) {
        auto cur_node = q.front();
        q.pop();
        for (auto &adj : cur_node->neighbors) {
            if (dict.find(adj) == dict.end()) {
                dict[adj] = new Node(adj->val);
                q.push(adj);

            }
            dict[cur_node]->neighbors.push_back(dict[adj]);
        }
    }
    return dict[node];
}