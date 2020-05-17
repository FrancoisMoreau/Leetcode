//
// Created by brayden on 2020-05-15.
//

#ifndef INC_101_150_PROBLEM116_H
#define INC_101_150_PROBLEM116_H

#include <MacTypes.h>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root);


#endif //INC_101_150_PROBLEM116_H
