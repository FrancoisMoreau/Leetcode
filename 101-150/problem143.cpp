//
// Created by brayden on 2020-05-30.
//

#include "problem143.h"
#include <vector>

using std::vector;

// I didn't solve this problem
// Always use this kind of prev-next way to solve problems !!! 80%, 5%
void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    // find the middle node
    ListNode *p1 = head;
    ListNode *p2 = head;
    while (p2->next && p2->next->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
    ListNode *p_mid = p1;
    ListNode *p_cur = p_mid->next;
    while (p_cur->next) {
        ListNode *tmp = p_cur->next;
        p_cur->next = tmp->next;
        tmp->next = p_mid->next;
        p_mid->next = tmp;
    }

    //Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
    p1 = head, p2 = p_mid->next;
    while (p1 != p_mid) {
        p_mid->next = p2->next;
        p2->next = p1->next;
        p1->next = p2;
        p1 = p2->next;
        p2 = p_mid->next;
    }

}

// Recursion method
// 76%, 33%
int get_length(ListNode *head) {
    int len = 0;
    while (head) {
        ++len;
        head = head->next;
    }
    return len;
}

ListNode *recursion_reorder(ListNode *head, int len) {
    if (len == 0) return nullptr;
    if (len == 1) return head;
    if (len == 2) return head->next;
    ListNode *tail = recursion_reorder(head->next, len - 2);
    ListNode *tmp = tail->next;
    tail->next = tail->next->next;
    tmp->next = head->next;
    head->next = tmp;
    return tail;
}

void reorderList2(ListNode* head) {
    ListNode *tail = nullptr;
    tail = recursion_reorder(head, get_length(head));
}
