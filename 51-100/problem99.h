//
// Created by brayden on 2020-05-17.
//

#ifndef INC_51_100_PROBLEM99_H
#define INC_51_100_PROBLEM99_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recoverTree(TreeNode* root);


#endif //INC_51_100_PROBLEM99_H
