//
// Created by brayden on 2020-06-15.
//

#ifndef INC_401_450_PROBLEM445_H
#define INC_401_450_PROBLEM445_H


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);


#endif //INC_401_450_PROBLEM445_H
