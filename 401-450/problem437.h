//
// Created by brayden on 2020-05-12.
//

#ifndef INC_401_450_PROBLEM437_H
#define INC_401_450_PROBLEM437_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int pathSum(TreeNode* root, int sum);

#endif //INC_401_450_PROBLEM437_H
