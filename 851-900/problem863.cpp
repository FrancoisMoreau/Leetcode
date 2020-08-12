//
// Created by brayden on 2020-05-12.
//

#include "problem863.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::unordered_map;
using std::pair;
using std::vector;
using std::unordered_set;

// My second try on 08/2020, dfs
// 94%， 64%
int find(TreeNode *node, TreeNode *target, unordered_map<TreeNode *, int> &dict) {
    if (!node) return -1;
    if (node == target) {
        dict[node] = 0;
        return 0;
    }
    int left = find(node->left, target, dict);
    if (left >= 0) {
        dict[node] = left + 1;
        return left + 1;
    }
    int right = find(node->right, target, dict);
    if (right >= 0) {
        dict[node] = right + 1;
        return right + 1;
    }
    return -1;
}

void dfs(TreeNode *node, const unordered_map<TreeNode *, int> &dict, int cur_len, int K, vector<int> &res) {
    if (!node) return;
    if (dict.find(node) != dict.end())
        cur_len = dict.at(node);
    if (cur_len == K) res.push_back(node->val);
    dfs(node->left, dict, cur_len + 1, K, res);
    dfs(node->right, dict, cur_len + 1, K, res);
}

std::vector<int> distanceK3(TreeNode* root, TreeNode* target, int K) {
    unordered_map<TreeNode *, int> dict;
    vector<int> res;
    find(root, target, dict);
    dfs(root, dict, 0, K, res);
    return res;
}

// bfs, 50%, 8%
void buildgraph(TreeNode *node, TreeNode *parent, unordered_map<TreeNode *, vector<TreeNode *>> &graph) {
    if (!node) return ;
    if (graph.find(node) == graph.end()) {
        graph[node] = {};
        if (parent) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        buildgraph(node->left, node, graph);
        buildgraph(node->right, node, graph);
    }
}

std::vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    unordered_map<TreeNode *, vector<TreeNode *>> graph;
    buildgraph(root, nullptr, graph);
    unordered_set<TreeNode *> visited;
    std::queue<TreeNode *> q;
    q.push(target);
    visited.insert(target);
    vector<int> res;
    while (!q.empty()) {
        int size = q.size();
        if (K == 0) {
            for (int i = 0; i < size; ++i) {
                res.push_back(q.front()->val);
                q.pop();
            }
            return res;
        }
        for (int i = 0; i < size; ++i) {
            TreeNode *node = q.front();
            q.pop();
            for (auto &adj : graph[node]) {
                if (visited.find(adj) != visited.end()) continue;
                visited.insert(adj);
                q.push(adj);
            }
        }
        --K;
    }
    return res;
}



// My first try on this problem on 05/2020
int find_parents(TreeNode *x, TreeNode *target, unordered_map<TreeNode *, pair<bool, int>> &par_dis) {
    if (!x) return 0;
    if (x == target) return 1;
    auto lhs = find_parents(x->left, target, par_dis);
    auto rhs = find_parents(x->right, target, par_dis);
    if (lhs) {
        par_dis.insert({x, {true, lhs}});
        return lhs + 1;
    } else if (rhs) {
        par_dis.insert({x, {false, rhs}});
        return rhs + 1;
    } else {
        return 0;
    }
}

void traverse(TreeNode *x, std::vector<int> &res, int left) {
    if (!x) return;
    if (left == 0) res.push_back(x->val);
    else {
        traverse(x->left, res, left - 1);
        traverse(x->right, res, left - 1);
    }
}

void get_res(const unordered_map<TreeNode *, pair<bool, int>> &par_dis, std::vector<int> &res, int K) {
    for (auto &node : par_dis) {
        if (node.second.second == K) res.push_back(node.first->val);
        else if (node.second.second < K) {
            if (node.second.first) traverse(node.first->left, res, K - node.second.second - 1);
            else traverse(node.first->right, res, K - node.second.second - 1);
        }
        else return;
    }
}

std::vector<int> distanceK2(TreeNode* root, TreeNode* target, int K) {
    if (!K) return {target->val};
    unordered_map<TreeNode *, std::pair<bool, int>> parent_dis;
    find_parents(root, target, parent_dis);
    std::vector<int> res;
    get_res(parent_dis, res, K);
    traverse(target, res, K);
    return res;
}