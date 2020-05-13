//
// Created by brayden on 2020-05-12.
//

#include "problem863.h"
#include <unordered_map>

using std::unordered_map;
using std::pair;

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

std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    if (!K) return {target->val};
    unordered_map<TreeNode *, std::pair<bool, int>> parent_dis;
    find_parents(root, target, parent_dis);
    std::vector<int> res;
    get_res(parent_dis, res, K);
    traverse(target, res, K);
    return res;
}