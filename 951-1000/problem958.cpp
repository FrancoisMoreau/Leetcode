//
// Created by brayden on 2020-08-16.
//

#include "problem958.h"
#include <queue>

using std::queue;

// 65%, 82%
bool isCompleteTree(TreeNode* root) {
    queue<TreeNode *> q;
    q.push(root);
    bool findempty = false;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (!node->left) {
            findempty = true;
        } else {
            if (findempty) return false;
            q.push(node->left);
        }
        if (!node->right) {
            findempty = true;
        } else {
          if (findempty) return false;
          q.push(node->right);
        }
    }
    return true;
}

// less code
bool isCompleteTree2(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    bool empty = false;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (!node) empty = true;
        else {
            if (empty) return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}