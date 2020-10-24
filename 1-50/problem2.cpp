//
// Created by brayden on 2020-10-23.
//

#include "problem2.h"


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int lhs = 0, rhs = 0, inc = 0, cur = 0;
    ListNode dummy(0);
    ListNode *pt = &dummy;
    while (l1 || l2) {
        lhs = l1 ? l1->val : 0;
        rhs = l2 ? l2->val : 0;
        cur = (lhs + rhs + inc) % 10;
        inc = (lhs + rhs + inc) / 10;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
        pt->next = new ListNode(cur);
        pt = pt->next;
    }
    if (inc) pt->next = new ListNode(inc);
    return dummy.next;
}