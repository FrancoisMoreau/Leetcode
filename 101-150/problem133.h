//
// Created by brayden on 2020-05-31.
//

#ifndef INC_101_150_PROBLEM133_H
#define INC_101_150_PROBLEM133_H

#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node* cloneGraph(Node* node);

#endif //INC_101_150_PROBLEM133_H
