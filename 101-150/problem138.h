//
// Created by brayden on 2020-06-03.
//

#ifndef INC_101_150_PROBLEM138_H
#define INC_101_150_PROBLEM138_H


#include <cstdlib>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head);



#endif //INC_101_150_PROBLEM138_H
