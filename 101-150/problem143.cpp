//
// Created by brayden on 2020-05-30.
//

#include "problem143.h"
#include <vector>

using std::vector;

// I didn't solve this problem

void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;

    // find the middle of the list
    ListNode *p1 = head;
    ListNode *p2 = head;
    while (p2->next != nullptr && p2->next->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    //reverse the half after middle: 1->2->3->4->5->6  to 1->2->3->6->5->4
    ListNode *pMiddle = p1;
    ListNode *pcur = p1->next;
    while (pcur != nullptr) {

    }
}