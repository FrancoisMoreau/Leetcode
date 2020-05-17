//
// Created by brayden on 2020-05-17.
//

#include "problem99.h"

#include <vector>

using std::vector;

// I didn't work this problem out
void recoverTree(TreeNode* root) {
    vector<TreeNode *> nodes{nullptr, nullptr, new TreeNode(INT_MIN)};
    std::swap(nodes[0]->val, nodes[1]->val);
}

void traverse(TreeNode *root, vector<TreeNode *> &nodes) {
    if (!root) return;
    traverse(root->left, nodes);
    if (nodes[2]->val > root->val) {
        if (!nodes[0])
            nodes[0] = nodes[2];
        if (nodes[0])
            nodes[1] = nodes[2];
    }
    nodes[2] = root;
    traverse(root->right, nodes);
}

// Morris traversal
// Do it later!