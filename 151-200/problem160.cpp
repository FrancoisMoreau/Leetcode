//
// Created by brayden on 2020-06-10.
//

#include <algorithm>
#include "problem160.h"

// I didn't solve this problem

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    auto a = headA, b = headB;
    while (a != b) {
        a = a == nullptr ? headB : a->next;
        b = b == nullptr ? headA : b->next;
    }
    return a;
}


// another solution:
// walk through A/B get their length, lenA, lenB
// then get their difference, abs(lenA - lenB), then let the longer one walk abs(lenA - lenB) first
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    int countA = 0, countB = 0;
    auto pA = headA, pB = headB;
    while (pA) {
        ++countA;
        pA = pA->next;
    }
    while (pB) {
        ++countB;
        pB = pB->next;
    }
    int diff = abs(countA - countB);
    pA = headA, pB = headB;
    if (countA < countB) std::swap(pA, pB);
    while (diff--) pA = pA->next;
    while (pA != pB) {
        pA = pA->next;
        pB = pB->next;
    }
    return pA;
}