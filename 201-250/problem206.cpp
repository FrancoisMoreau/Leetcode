//
// Created by brayden on 2020-05-31.
//

#include "problem206.h"

// iteration
ListNode* reverseList2(ListNode* head) {
    ListNode *prev = nullptr, *cur = head, *next = nullptr;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

ListNode *reverseList3(ListNode *head) {
    ListNode *prev = new ListNode;
    prev->next = head;
    while (head && head->next) {
        ListNode *tmp = head->next;
        head->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }
    return prev->next;
}



// recursion
ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *reversed = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return head;
}