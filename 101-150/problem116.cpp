//
// Created by brayden on 2020-05-15.
//

#include "problem116.h"

#include <vector>

using std::vector;

// My solution
void subconnect(vector<Node *> nodes) {
    if (nodes.empty()) return;
    vector<Node *> next_lvl;
    if (nodes[0]->left) {
        next_lvl.reserve(2 * nodes.size());
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
            next_lvl.push_back(nodes[i]->left);
            next_lvl.push_back(nodes[i]->right);
        }
        next_lvl.push_back(nodes.back()->left);
        next_lvl.push_back(nodes.back()->right);
    }
    else {
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
        }
    }
    subconnect(next_lvl);
}

Node* connect2(Node* root) {
    subconnect({root});
    return root;
}

// Iterative solution

Node *connect(Node *root) {
    if (!root) return root;
    Node *raw = root;
    while(root -> left)
    {
        Node *p = root;
        while(p)
        {
            p -> left -> next = p -> right;
            if(p -> next)
                p -> right -> next = p -> next -> left;
            p = p -> next;
        }
        root = root -> left;
    }
    return raw;
}