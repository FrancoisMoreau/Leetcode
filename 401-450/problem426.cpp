//
// Created by brayden on 2020-07-26.
//

#include "problem426.h"
#include <queue>

using std::queue;

// My solution
void inorder(TreeNode *node, queue<TreeNode *> &q) {
    if (!node) return;
    inorder(node->left, q);
    q.push(node);
    inorder(node->right, q);
}

TreeNode * treeToDoublyList(TreeNode * root) {
    queue<TreeNode *> q;
    inorder(root, q);
    TreeNode *first = q.front();
    TreeNode *prev = first, *cur = prev;
    while (!q.empty()) {
        cur = q.front();
        prev->right = cur;
        cur->left = prev;
        q.pop();
        prev = cur;
    }
    prev->right = first;
    first->left = prev;
    return first;
}

//without queue
void other_inorder(TreeNode *node, TreeNode *&prev, TreeNode *&head) {
    if (!node) return;
    other_inorder(node->left, prev, head);
    if (!head) {
        head = node;
        prev = node;
    } else {
        prev->right = node;
        node->left = prev;
        prev = node;
    }
    other_inorder(node->right, prev, head);
}

TreeNode *treeToDoublyList2(TreeNode *root) {
    if (!root) return nullptr;
    TreeNode *head, *prev;
    other_inorder(root, prev, head);
    prev->right = head;
    head->left = prev;
    return head;
}

// we can also use stack to mimic recursion
