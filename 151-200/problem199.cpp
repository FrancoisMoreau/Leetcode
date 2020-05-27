//
// Created by brayden on 2020-05-25.
//

#include "problem199.h"

using std::vector;


// My solution
void subview(TreeNode *node, vector<int> &res, int height) {
    if (!node) return;
    if (res.size() < height) {
        res.push_back(node->val);
    }
    subview(node->right, res, height + 1);
    subview(node->left, res, height + 1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    subview(root, res, 1);
    return res;
}

// 