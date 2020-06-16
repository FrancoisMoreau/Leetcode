//
// Created by brayden on 2020-06-15.
//

#include "problem445.h"
#include <unordered_map>
#include <stack>

using std::stack;
using std::unordered_map;

// My solution, used map, not elegant, 15%, 30%
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int lhs = 0, rhs = 0;
    unordered_map<int, ListNode *> lhs_map, rhs_map;
    while (l1) {
        lhs_map[lhs++] = l1;
        l1 = l1->next;
    }
    while (l2) {
        rhs_map[rhs++] = l2;
        l2 = l2->next;
    }

    ListNode *next = nullptr, *cur = nullptr;
    int carry = 0;
    for (int i = --lhs, j = --rhs; i >= 0 || j >= 0; --i, --j) {
        int lhs_val = i >= 0 ? lhs_map[i]->val : 0;
        int rhs_val = j >= 0 ? rhs_map[j]->val : 0;
        int sum = lhs_val + rhs_val + carry;
        cur = new ListNode(sum % 10);
        cur->next = next;
        next = cur;
        carry = sum / 10;
    }
    if (carry) {
        cur = new ListNode(carry);
        cur->next = next;
    }
    return cur;
}

// using stack, 60%, 15%
ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
    stack<int> stk1, stk2;
    while (l1) {
        stk1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        stk2.push(l2->val);
        l2 = l2->next;
    }

    int sum = 0;
    ListNode *list = new ListNode(0);
    while (!stk1.empty() || !stk2.empty()) {
        if (!stk1.empty()) {
            sum += stk1.top();
            stk1.pop();
        }
        if (!stk2.empty()) {
            sum += stk2.top();
            stk2.pop();
        }
        list->val = sum % 10;
        ListNode *head = new ListNode(sum / 10);
        head->next = list;
        list = head;
        sum /= 10;
    }
    return list->val == 0 ?  list->next : list;
}

// without using any data structure, 80%, 50%
int get_length(ListNode *l) {
    int len = 0;
    while (l) {
        ++len;
        l = l->next;
    }
    return len;
}

ListNode *add_aux(ListNode *l1, ListNode *l2, int k, int &carry) {
    if (l2 == nullptr) return nullptr;
    ListNode *p = new ListNode(l1->val);
    if (k > 0) {
        p->next = add_aux(l1->next, l2, k - 1, carry);
    } else {
        p->val += l2->val;
        p->next = add_aux(l1->next, l2->next, k, carry);
    }
    p->val += carry;
    carry = p->val / 10;
    p->val %= 10;
    return p;
}

ListNode *addTwoNumbers3(ListNode *l1, ListNode *l2) {
    int n1 = get_length(l1), n2 = get_length(l2);
    int carry = 0;
    ListNode *h = new ListNode(1);
    h->next = n1 > n2 ? add_aux(l1, l2, n1 - n2, carry) : add_aux(l2, l1, n2 - n1, carry);
    return  carry == 1 ? h : h->next;
}