//
// Created by brayden on 2020-06-16.
//

#include "problem117.h"

#include <queue>

using std::queue;

// 98%, 30%， O(n) space
Node* connect117(Node* root) {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            Node *cur = q.front();
            q.pop();
            if (i < n - 1) cur->next = q.front();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return root;
}

// O(1) space, 55%, 73%
Node *connect117_2(Node *root) {
    if (!root) return root;
    Node *cur = root;
    Node dummy = Node(0);
    Node *nextDummyHead = &dummy;
    Node *p = nextDummyHead;
    while (cur) {
        if (cur->left) {
            p->next = cur->left;
            p = p->next;
        }
        if (cur->right) {
            p->next = cur->right;
            p = p->next;
        }
        if (cur->next) {
            cur = cur->next;
        } else {
            cur = nextDummyHead->next;
            nextDummyHead->next = nullptr;
            p = nextDummyHead;
        }
    }
    return root;
}