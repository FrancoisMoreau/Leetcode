//
// Created by brayden on 2020-05-29.
//

#ifndef INC_901_950_PROBLEM938_H
#define INC_901_950_PROBLEM938_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode* root, int L, int R);

#endif //INC_901_950_PROBLEM938_H
