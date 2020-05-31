//
// Created by brayden on 2020-05-30.
//

#ifndef INC_101_150_PROBLEM143_H
#define INC_101_150_PROBLEM143_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head);

#endif //INC_101_150_PROBLEM143_H
