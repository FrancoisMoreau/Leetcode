//
// Created by brayden on 2020-05-14.
//

#include "problem23.h"

#include <set>
#include <queue>

using std::multiset;

using std::vector;

// My solution 5/14/2020
ListNode* mergeKLists2(vector<ListNode*>& lists) {
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

// Totally forget that I can use PriorityQueue to solve this problem
// in place, 80%, 90%
ListNode *mergeKLists3(vector<ListNode*> &lists) {
    auto cmp = [](const ListNode *lhs, const ListNode *rhs) {
        return lhs->val > rhs->val;
    };
    std::priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
    for (auto &l : lists) {
        if (l) pq.push(l);
    }
    if (pq.empty()) return nullptr;
    ListNode *res = pq.top();
    pq.pop();
    if (res->next) pq.push(res->next);
    auto tail = res;
    while (!pq.empty()) {
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;
        if (tail->next)
            pq.push(tail->next);
    }
    return res;
}

// divide and conquer
// 98%, 91%
ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;
    return dummy.next;
}

ListNode *mergeKLists(vector<ListNode*> &lists, int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        return merge2Lists(mergeKLists(lists, lo, mid), mergeKLists(lists, mid + 1, hi));
    }
    return lists[lo];
}

ListNode *mergeKLists(vector<ListNode*> &lists) {
    if (lists.empty()) return nullptr;
    int lo = 0, hi = lists.size() - 1;
    return mergeKLists(lists, lo, hi);
}


// review merge sort first
void merge(vector<int> &v, vector<int> &v_helper, int lo, int mid, int hi) {
    std::copy(v.begin() + lo, v.begin() + hi + 1, v_helper.begin() + lo);
    int i = lo, j = mid  + 1;
    for (int k = lo; k <= hi; ++k) {
        if (i > mid) v[k] = v_helper[j++];
        else if (j > hi) v[k] = v_helper[i++];
        else if (v_helper[i] <= v_helper[j])
            v[k] = v_helper[i++];
        else
            v[k] = v_helper[j++];
    }
}

void mergesort(vector<int> &v, vector<int> &v_helper, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    mergesort(v, v_helper, lo, mid);
    mergesort(v, v_helper, mid + 1, hi);
    merge(v, v_helper, lo, mid, hi);
}

void mergesort(vector<int> &v) {
    int lo = 0, hi = v.size() - 1;
    vector<int> v_helper(v.size());
    mergesort(v, v_helper, lo, hi);
}