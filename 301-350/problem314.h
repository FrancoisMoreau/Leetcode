//
// Created by brayden on 2020-08-11.
//

#ifndef INC_301_350_PROBLEM314_H
#define INC_301_350_PROBLEM314_H

#include <vector>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
    }
};

std::vector<std::vector<int>> verticalOrder(TreeNode * root);

#endif //INC_301_350_PROBLEM314_H
