//
// Created by brayden on 2020-05-12.
//

#include "problem173.h"

#include <stack>
using std::stack;

// I should remember this way of processing
// next() and hasNext() run in O(1) time, uses O(h) memory
class BSTIterator2 {
public:
    BSTIterator2(TreeNode *root) {
        pushAll(root);
    }

    int next() {
        TreeNode *tmp = stk.top();
        stk.pop();
        pushAll(tmp->right);
        return tmp->val;
    }

    bool hasNext() {
        return !stk.empty();
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != nullptr; node = node->left)
            stk.push(node);
    }

    stack<TreeNode *> stk;

};