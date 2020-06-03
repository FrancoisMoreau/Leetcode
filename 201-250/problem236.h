//
// Created by brayden on 2020-06-02.
//

#ifndef INC_201_250_PROBLEM236_H
#define INC_201_250_PROBLEM236_H

#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);


#endif //INC_201_250_PROBLEM236_H
