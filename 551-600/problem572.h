//
// Created by brayden on 2020-05-10.
//

#ifndef INC_551_600_PROBLEM572_H
#define INC_551_600_PROBLEM572_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isSubtree(TreeNode* s, TreeNode* t);



#endif //INC_551_600_PROBLEM572_H
