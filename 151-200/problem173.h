//
// Created by brayden on 2020-05-12.
//

#ifndef INC_151_200_PROBLEM173_H
#define INC_151_200_PROBLEM173_H

#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// My solution, copied from Algorithms
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    /** @return the next smallest number */
    int next() {
        int out = keys.front();
        keys.pop();
        return out;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (!keys.empty())
            return true;
        else
            return false;
    }
private:
    void inorder(TreeNode *x) {
        if (!x) return;
        inorder(x->left);
        keys.push(x->val);
        inorder(x->right);
    }
    std::queue<int> keys;
};



#endif //INC_151_200_PROBLEM173_H
