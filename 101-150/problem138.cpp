//
// Created by brayden on 2020-06-03.
//

#include "problem138.h"

#include <unordered_map>
using std::unordered_map;

// using hash, O(n) extra space, O(n) time
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    Node *new_head = new Node(head->val);
    Node *raw_p = head, *new_p = new_head;
    unordered_map<Node *, Node *> dict;
    dict[head] = new_head;
    while (raw_p->next) {
        new_p->next = new Node(raw_p->next->val);
        raw_p = raw_p->next;
        new_p = new_p->next;
        dict[raw_p]  = new_p;
    }
    raw_p = head, new_p = new_head;
    while (raw_p) {
        new_p->random = dict[raw_p->random];
        raw_p = raw_p->next;
        new_p = new_p->next;
    }
    return new_head;
}

// O(1) extra space, 90%, 100%
Node *copyRandomList2(Node *head) {
    if (!head) return nullptr;
    Node *new_head, *l1, *l2;
    // First round, make copy of each node and link them together side by side
    for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
        l2 = new Node(l1->val);
        l2->next = l1->next;
        l1->next = l2;
    }

    // Second round, assgin random pointers for the copied nodes
    new_head = head->next;
    for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
        if (l1->random) l1->next->random = l1->random->next;
    }

    // Third round, restore the original list, and extract the copied list
    for (l1 = head; l1 != nullptr; l1 = l1->next) {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next) l2->next = l2->next->next;
    }
    return new_head;

}