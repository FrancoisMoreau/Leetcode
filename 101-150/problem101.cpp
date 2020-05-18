//
// Created by brayden on 2020-05-17.
//

#include <vector>
#include <deque>
#include <queue>
#include "problem101.h"

using std::vector;

// recursion
//Time Limit Exceeded
bool subsym(vector<TreeNode *> nodes) {
    if (nodes.empty()) return true;
    vector<TreeNode *> next;
    auto start = nodes.cbegin();
    for (auto end = nodes.cend() - 1; start <= end; ++start, --end) {
        if ((*start)->left) {
            if (!(*end)->right) return  false;
            if ((*start)->left->val != (*end)->right->val) return false;
            next.push_back((*start)->left);
        }
        if ((*start)->right) {
            if (!(*end)->left) return false;
            if ((*start)->right->val != ((*end)->left->val)) return false;
            next.push_back((*start)->right);
        }
    }
    while (start != nodes.cend()) {
        if ((*start)->left) next.push_back((*start)->left);
        if ((*start)->right) next.push_back((*start)->right);
    }
    return subsym(next);
}

bool isSymmetric2(TreeNode* root) {
    if (!root) return true;
    return subsym({root});
}

//recursive implementation
bool compare(TreeNode *lhs, TreeNode *rhs) {
    if (!lhs && !rhs) return true;
    if (!lhs || !rhs) return false;
    if (lhs->val != rhs->val) return false;
    return (compare(lhs->left, rhs->right) && compare(lhs->right, rhs->left));
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return compare(root->left, root->right);
}

//iterative implementation
// I didn't implemented myself after half an hour's try
// 78% time
bool isSymmetric3(TreeNode *root) {
    if (!root) return true;
    std::queue<TreeNode *> q1, q2;
    q1.push(root->left);
    q2.push(root->right);
    TreeNode *lhs, *rhs;
    while (!q1.empty() && !q2.empty()) {
        lhs = q1.front();
        q1.pop();
        rhs = q2.front();
        q2.pop();
        if (!lhs && !rhs) continue;
        if (!lhs || !rhs) return false;
        if (lhs->val != rhs->val) return false;
        q1.push(lhs->left);
        q1.push(lhs->right);
        q2.push(rhs->right);
        q2.push(rhs->left);
    }
    return true;
}