//
// Created by brayden on 2020-05-31.
//

#include "problem92.h"

// solution
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

// My solution after several months, Oct 2020
ListNode* reverseBetween2(ListNode* head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pt = &dummy;
    int count = 1;
    while (count < m) {
        pt = pt->next;
        count++;
    }
    ListNode *prev = pt, *cur = pt->next, *next = nullptr;
    while (count < n) {
        next = cur->next->next;
        cur->next->next = prev->next;
        prev->next = cur->next;
        cur->next = next;
        count++;
    }
    return dummy.next;
}

// recursion

