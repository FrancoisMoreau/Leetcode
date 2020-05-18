//
// Created by brayden on 2020-05-18.
//

#include "problem95.h"

using std::vector;

// I didn't solve this problem, again...
// Divide and conquer
vector<TreeNode *> subgenerate(int start, int end) {
    if (start > end) return {nullptr};
    vector<TreeNode *> res;
    for (int i = start; i <= end; ++i) {
        auto lhs = subgenerate(start, i - 1);
        auto rhs = subgenerate(i + 1, end);
        for (auto &j : lhs) {
            for (auto &k : rhs) {
                TreeNode *root = new TreeNode(i);
                root->left = j;
                root->right = k;
                res.push_back(root);
            }
        }
    }
    return  res;
}

vector<TreeNode*> generateTrees2(int n) {
    return subgenerate(1, n);
}

// Dynamic Programming
// time: 99.96%, space: 100%...
// Oh my gosh dp!
TreeNode *clone(TreeNode *x, int offset) {
    if (!x) return nullptr;
    TreeNode *node = new TreeNode(x->val + offset);
    node->left = clone(x->left, offset);
    node->right = clone(x->right, offset);
    return node;
}

vector<TreeNode *> generateTrees(int n) {
    vector<vector<TreeNode *>> res(n + 1);
    if (!n) return res[0];
    res[0].push_back(nullptr);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (auto &lhs : res[j]) {
                for (auto &rhs : res[i - j - 1]) {
                    TreeNode *node = new TreeNode(j + 1);
                    node->left = lhs;
                    node->right = clone(rhs, j + 1);
                    res[i].push_back(node);
                }
            }
        }
    }
    return res[n];
}