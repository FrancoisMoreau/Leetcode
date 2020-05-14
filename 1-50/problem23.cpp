//
// Created by brayden on 2020-05-14.
//

#include "problem23.h"

#include <set>
#include <queue>

using std::multiset;

using std::vector;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    std::priority_queue<int, vector<int>, std::greater<int>> minpq;
    for (auto &i : lists) {
        while (i) {
            minpq.emplace(i->val);
            i = i->next;
        }
    }
    ListNode dummy(1);
    ListNode *pt = &dummy;
    while (!minpq.empty()) {
        ListNode *tmp = new ListNode(minpq.top());
        minpq.pop();
        pt->next = tmp;
        pt = pt->next;
    }
    return dummy.next;
}