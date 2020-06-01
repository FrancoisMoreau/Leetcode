//
// Created by brayden on 2020-05-31.
//

#include "problem133.h"

#include <unordered_map>
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

// bfs
//https://leetcode.com/problems/clone-graph/discuss/42313/C%2B%2B-BFSDFS