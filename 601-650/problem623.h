//
// Created by brayden on 2020-10-27.
//

#ifndef INC_601_650_PROBLEM623_H
#define INC_601_650_PROBLEM623_H

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *construct(TreeNode *root, int v, int d, bool isleft);

#endif //INC_601_650_PROBLEM623_H
