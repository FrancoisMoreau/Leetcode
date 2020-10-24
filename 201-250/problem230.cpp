//
// Created by brayden on 2020-10-22.
//

#include "problem230.h"


#include <vector>
#include <stack>


// recursion
void inorder(TreeNode *node, std::vector<int> &vec) {
    if (!node) return;
    inorder(node->left, vec);
    vec.push_back(node->val);
    inorder(node->right, vec);
}

int kthSmallest(TreeNode* root, int k) {
    std::vector<int> vec;
    inorder(root, vec);
    return vec[k - 1];
}

// iteration
int kthSmallest2(TreeNode *root, int k) {
    std::stack<TreeNode *> stk;
    while (true) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (--k == 0) return root->val;
        root = root->right;
    }
}