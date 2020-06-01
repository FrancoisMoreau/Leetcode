//
// Created by brayden on 2020-05-31.
//

#ifndef INC_201_250_PROBLEM206_H
#define INC_201_250_PROBLEM206_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head);

#endif //INC_201_250_PROBLEM206_H
