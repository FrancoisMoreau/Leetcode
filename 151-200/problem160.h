//
// Created by brayden on 2020-06-10.
//

#ifndef INC_151_200_PROBLEM160_H
#define INC_151_200_PROBLEM160_H


#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);


#endif //INC_151_200_PROBLEM160_H
