//
// Created by brayden on 2020-05-31.
//

#include "problem92.h"


ListNode* reverseBetween(ListNode* head, int m, int n) {
    n = n - m;
    ListNode node(0);
    ListNode *dummy = &node;
    dummy->next = head;
    ListNode *prev = dummy;
    while (--m) prev = prev->next;
    ListNode *cur = prev->next;
    while (n--) {
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }
    return dummy->next;
}
