//
// Created by brayden on 2020-06-10.
//

#include "problem148.h"

// My solution, 97%, 80%
// However, it uses recursion, so the space is O(lgN), not O(1)
ListNode *merge(ListNode *lhs, ListNode *rhs) {
    ListNode dummy(0);
    ListNode *pt = &dummy;
    while (lhs && rhs) {
        if (lhs->val < rhs->val) {
            pt->next = lhs;
            lhs = lhs->next;
        } else {
            pt->next = rhs;
            rhs = rhs->next;
        }
        pt = pt->next;
    }
    if (lhs) pt->next = lhs;
    if (rhs) pt->next = rhs;
    return dummy.next;
}

ListNode *sortList(ListNode *cur_head, int n) {
    if (n <= 1) return cur_head;
    int mid = n / 2;
    ListNode *mid_head = cur_head;
    while (--mid) mid_head = mid_head->next;
    auto tmp = mid_head->next;
    mid_head->next = nullptr;
    mid_head = tmp;
    cur_head = sortList(cur_head, n / 2);
    mid_head = sortList(mid_head, n - n / 2);
    return merge(cur_head, mid_head);
}

ListNode* sortList(ListNode* head) {
    int n = 0;
    ListNode *pt = head;
    while (pt) {
        ++n;
        pt = pt->next;
    }
    return sortList(head, n);
}


// To make the space complexity O(1), we can use iteration
ListNode *split(ListNode *cur_head, int step) {
    for (int i = 1; cur_head && i < step; ++i) {
        cur_head = cur_head->next;
    }
    if (!cur_head) return nullptr;
    ListNode *second = cur_head->next;
    cur_head->next = nullptr;
    return second;
}

ListNode *merge2(ListNode *lhs, ListNode *rhs, ListNode *head) {
    while (lhs && rhs) {
        if (lhs->val > rhs->val) {
            head->next = rhs;
            rhs = rhs->next;
        } else {
            head->next = lhs;
            lhs = lhs->next;
        }
        head = head->next;
    }
    head->next = lhs ? lhs : rhs;
    while (head->next) head = head->next;
    return head;
}

ListNode *sortList2(ListNode *head) {
    int n = 0;
    ListNode *pt = head;
    while (pt) {
        ++n;
        pt = pt->next;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode *lhs, *rhs, *tail;
    for (int step = 1; step < n; step <<= 1) {
        pt = dummy.next;
        tail = &dummy;
        while (pt) {
            lhs = pt;
            rhs = split(lhs, step);
            pt = split(rhs, step);
            tail = merge2(lhs, rhs, tail);
        }
    }
    return dummy.next;
}