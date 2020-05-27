//
// Created by brayden on 2020-05-10.
//

#include <cstdio>
#include "problem572.h"



// My solution, time and memory are bad
/*
bool isSame(TreeNode *s, TreeNode *t, bool match) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val == t->val) {
        bool res = isSame(s->left, t->left, true) && isSame(s->right, t->right, true);
        if (match)
            return res;
        else
            return res || isSame(s->left, t, match) || isSame(s->right, t, match);
    } else {
        if (match) return false;
        return isSame(s->left, t, match) || isSame(s->right, t, match);
    }
}
 */

bool isSame(TreeNode *s, TreeNode *t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val == t->val)
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    else
        return false;
}


bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    if (isSame(s, t)) return true;
    // here need to use isSubtree
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}